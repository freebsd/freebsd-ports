--- hotspot/src/os/bsd/vm/os_bsd.cpp.orig	2017-12-01 00:32:02 UTC
+++ hotspot/src/os/bsd/vm/os_bsd.cpp
@@ -1588,6 +1588,10 @@ void * os::dll_load(const char *filename, char *ebuf, 
   #define EM_X86_64       62              /* AMD x86-64 */
   #endif
 
+  #ifndef EM_AARCH64
+  #define EM_AARCH64     183              /* ARM AARCH64 */
+  #endif
+
   static const arch_t arch_array[]={
     {EM_386,         EM_386,     ELFCLASS32, ELFDATA2LSB, (char*)"IA 32"},
     {EM_486,         EM_386,     ELFCLASS32, ELFDATA2LSB, (char*)"IA 32"},
@@ -1604,7 +1608,8 @@ void * os::dll_load(const char *filename, char *ebuf, 
     {EM_MIPS_RS3_LE, EM_MIPS_RS3_LE, ELFCLASS32, ELFDATA2LSB, (char*)"MIPSel"},
     {EM_MIPS,        EM_MIPS,    ELFCLASS32, ELFDATA2MSB, (char*)"MIPS"},
     {EM_PARISC,      EM_PARISC,  ELFCLASS32, ELFDATA2MSB, (char*)"PARISC"},
-    {EM_68K,         EM_68K,     ELFCLASS32, ELFDATA2MSB, (char*)"M68k"}
+    {EM_68K,         EM_68K,     ELFCLASS32, ELFDATA2MSB, (char*)"M68k"},
+    {EM_AARCH64,     EM_AARCH64, ELFCLASS64, ELFDATA2LSB, (char*)"AARCH64"},
   };
 
   #if  (defined IA32)
@@ -1621,6 +1626,8 @@ void * os::dll_load(const char *filename, char *ebuf, 
     static  Elf32_Half running_arch_code=EM_PPC64;
   #elif  (defined __powerpc__)
     static  Elf32_Half running_arch_code=EM_PPC;
+  #elif  (defined AARCH64)
+    static  Elf32_Half running_arch_code=EM_AARCH64;
   #elif  (defined ARM)
     static  Elf32_Half running_arch_code=EM_ARM;
   #elif  (defined S390)
@@ -1637,7 +1644,7 @@ void * os::dll_load(const char *filename, char *ebuf, 
     static  Elf32_Half running_arch_code=EM_68K;
   #else
     #error Method os::dll_load requires that one of following is defined:\
-         IA32, AMD64, IA64, __sparc, __powerpc__, ARM, S390, ALPHA, MIPS, MIPSEL, PARISC, M68K
+         AARCH64, IA32, AMD64, IA64, __sparc, __powerpc__, ARM, S390, ALPHA, MIPS, MIPSEL, PARISC, M68K
   #endif
 
   // Identify compatability class for VM's architecture and library's architecture
@@ -2395,14 +2402,18 @@ static address _highest_vm_reserved_address = NULL;
 // 'requested_addr' is only treated as a hint, the return value may or
 // may not start from the requested address. Unlike Bsd mmap(), this
 // function returns NULL to indicate failure.
-static char* anon_mmap(char* requested_addr, size_t bytes, bool fixed) {
+static char* anon_mmap(char* requested_addr, size_t bytes, size_t alignment_hint, bool fixed) {
   char * addr;
   int flags;
 
+  assert(!(fixed && (alignment_hint > 0)), "alignment hint meaningless with fixed mmap");
+
   flags = MAP_PRIVATE | MAP_ANONYMOUS;
   if (fixed) {
     assert((uintptr_t)requested_addr % os::Bsd::page_size() == 0, "unaligned address");
     flags |= MAP_FIXED;
+  } else if (alignment_hint > 0) {
+    flags |= MAP_ALIGNED(ffs(alignment_hint) - 1);
   }
 
   // Map reserved/uncommitted pages PROT_NONE so we fail early if we
@@ -2434,7 +2445,7 @@ static int anon_munmap(char * addr, size_t size) {
 
 char* os::pd_reserve_memory(size_t bytes, char* requested_addr,
                          size_t alignment_hint) {
-  return anon_mmap(requested_addr, bytes, (requested_addr != NULL));
+  return anon_mmap(requested_addr, bytes, alignment_hint, (requested_addr != NULL));
 }
 
 bool os::pd_release_memory(char* addr, size_t size) {
@@ -2480,19 +2491,93 @@ bool os::unguard_memory(char* addr, size_t size) {
   return bsd_mprotect(addr, size, PROT_READ|PROT_WRITE);
 }
 
-bool os::Bsd::hugetlbfs_sanity_check(bool warn, size_t page_size) {
-  return false;
-}
-
 // Large page support
 
 static size_t _large_page_size = 0;
 
 void os::large_page_init() {
+  if (UseLargePages) {
+    // print a warning if any large page related flag is specified on command line
+    bool warn_on_failure = !FLAG_IS_DEFAULT(UseLargePages)        ||
+                           !FLAG_IS_DEFAULT(LargePageSizeInBytes);
+
+    UseLargePages = Bsd::superpage_sanity_check(warn_on_failure, &_large_page_size);
+  }
 }
 
+// Insertion sort for small arrays (descending order).
+static void insertion_sort_descending(size_t* array, int len) {
+  for (int i = 0; i < len; i++) {
+    size_t val = array[i];
+    for (size_t key = i; key > 0 && array[key - 1] < val; --key) {
+      size_t tmp = array[key];
+      array[key] = array[key - 1];
+      array[key - 1] = tmp;
+    }
+  }
+}
 
+bool os::Bsd::superpage_sanity_check(bool warn, size_t* page_size) {
+#ifdef __FreeBSD__
+  const unsigned int usable_count = VM_Version::page_size_count();
+  if (usable_count == 1) {
+    return false;
+  }
+
+  // Fill the array of page sizes.
+  int n = ::getpagesizes(_page_sizes, page_sizes_max);
+  assert(n > 0, "FreeBSD bug?");
+
+  if (n == page_sizes_max) {
+    // Add a sentinel value (necessary only if the array was completely filled
+    // since it is static (zeroed at initialization)).
+    _page_sizes[--n] = 0;
+    DEBUG_ONLY(warning("increase the size of the os::_page_sizes array.");)
+  }
+  assert(_page_sizes[n] == 0, "missing sentinel");
+  trace_page_sizes("available page sizes", _page_sizes, n);
+
+  if (n == 1) return false;     // Only one page size available.
+
+  // Skip sizes larger than 4M (or LargePageSizeInBytes if it was set) and
+  // select up to usable_count elements.  First sort the array, find the first
+  // acceptable value, then copy the usable sizes to the top of the array and
+  // trim the rest.  Make sure to include the default page size :-).
+  //
+  // A better policy could get rid of the 4M limit by taking the sizes of the
+  // important VM memory regions (java heap and possibly the code cache) into
+  // account.
+  insertion_sort_descending(_page_sizes, n);
+  const size_t size_limit =
+    FLAG_IS_DEFAULT(LargePageSizeInBytes) ? 4 * M : LargePageSizeInBytes;
+  int beg;
+  for (beg = 0; beg < n && _page_sizes[beg] > size_limit; ++beg) /* empty */ ;
+  const int end = MIN2((int)usable_count, n) - 1;
+  for (int cur = 0; cur < end; ++cur, ++beg) {
+    _page_sizes[cur] = _page_sizes[beg];
+  }
+  _page_sizes[end] = vm_page_size();
+  _page_sizes[end + 1] = 0;
+
+  if (_page_sizes[end] > _page_sizes[end - 1]) {
+    // Default page size is not the smallest; sort again.
+    insertion_sort_descending(_page_sizes, end + 1);
+  }
+  *page_size = _page_sizes[0];
+
+  trace_page_sizes("usable page sizes", _page_sizes, end + 1);
+  return true;
+#else
+  return false;
+#endif
+}
+
+
 char* os::reserve_memory_special(size_t bytes, size_t alignment, char* req_addr, bool exec) {
+#ifdef __FreeBSD__
+  fatal("os::reserve_memory_special should not be called on FreeBSD.");
+  return NULL;
+#else
   fatal("This code is not used or maintained.");
 
   // "exec" is passed in but not used.  Creating the shared image for
@@ -2552,9 +2637,14 @@ char* os::reserve_memory_special(size_t bytes, size_t 
   MemTracker::record_virtual_memory_reserve_and_commit((address)addr, bytes, CALLER_PC);
 
   return addr;
+#endif
 }
 
 bool os::release_memory_special(char* base, size_t bytes) {
+#ifdef __FreeBSD__
+  fatal("os::release_memory_special should not be called on FreeBSD.");
+  return false;
+#else
   if (MemTracker::tracking_level() > NMT_minimal) {
     Tracker tkr = MemTracker::get_virtual_memory_release_tracker();
     // detaching the SHM segment will also delete it, see reserve_memory_special()
@@ -2568,21 +2658,28 @@ bool os::release_memory_special(char* base, size_t byt
   } else {
     return shmdt(base) == 0;
   }
+#endif
 }
 
 size_t os::large_page_size() {
   return _large_page_size;
 }
 
-// HugeTLBFS allows application to commit large page memory on demand;
-// with SysV SHM the entire memory region must be allocated as shared
-// memory.
+// FreeBSD allows application to commit large page memory on demand.
 bool os::can_commit_large_page_memory() {
-  return UseHugeTLBFS;
+#ifdef __FreeBSD__
+  return true;
+#else
+  return false;
+#endif
 }
 
 bool os::can_execute_large_page_memory() {
-  return UseHugeTLBFS;
+#ifdef __FreeBSD__
+  return true;
+#else
+  return false;
+#endif
 }
 
 // Reserve memory at an arbitrary address, only if that area is
@@ -2614,7 +2711,7 @@ char* os::pd_attempt_reserve_memory_at(size_t bytes, c
 
   // Bsd mmap allows caller to pass an address as hint; give it a try first,
   // if kernel honors the hint then we can return immediately.
-  char * addr = anon_mmap(requested_addr, bytes, false);
+  char * addr = anon_mmap(requested_addr, bytes, 0, false);
   if (addr == requested_addr) {
      return requested_addr;
   }
@@ -4010,15 +4010,19 @@
 }
 
 void os::set_native_thread_name(const char *name) {
-#if defined(__APPLE__) && MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_5
-  // This is only supported in Snow Leopard and beyond
   if (name != NULL) {
+#if defined(__APPLE__) && MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_5
+    // This is only supported in Snow Leopard and beyond
     // Add a "Java: " prefix to the name
     char buf[MAXTHREADNAMESIZE];
     snprintf(buf, sizeof(buf), "Java: %s", name);
     pthread_setname_np(buf);
-  }
+#elif defined(__FreeBSD__)
+    char buf[MAXCOMLEN+1];
+    strlcpy(buf, name, sizeof(buf));
+    pthread_set_name_np(pthread_self(), buf);
 #endif
+  }
 }
 
 bool os::distribute_processes(uint length, uint* distribution) {
