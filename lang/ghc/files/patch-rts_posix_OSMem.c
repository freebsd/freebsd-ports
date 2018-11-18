--- rts/posix/OSMem.c.orig      2017-11-28 16:39:14 UTC
+++ rts/posix/OSMem.c
@@ -36,6 +36,10 @@
 #if defined(HAVE_NUMAIF_H)
 #include <numaif.h>
 #endif
+#if defined(HAVE_SYS_RESOURCE_H) && defined(HAVE_SYS_TIME_H)
+#include <sys/time.h>
+#include <sys/resource.h>
+#endif

 #include <errno.h>

@@ -45,6 +49,29 @@
 #include <sys/sysctl.h>
 #endif

+#ifndef MAP_FAILED
+# define MAP_FAILED ((void *)-1)
+#endif
+
+#if defined(hpux_HOST_OS)
+# ifndef MAP_ANON
+#  define MAP_ANON MAP_ANONYMOUS
+# endif
+#endif
+
+#ifndef darwin_HOST_OS
+# undef RESERVE_FLAGS
+# if defined(MAP_GUARD)
+#  define RESERVE_FLAGS  MAP_GUARD /* FreeBSD */
+# elif defined(MAP_NORESERVE)
+#  define RESERVE_FLAGS  MAP_NORESERVE | MAP_ANON | MAP_PRIVATE;
+# else
+#  if defined(USE_LARGE_ADDRESS_SPACE)
+#   error USE_LARGE_ADDRESS_SPACE needs MAP_NORESERVE or MAP_GUARD
+#  endif
+# endif
+#endif
+
 static void *next_request = 0;

 void osMemInit(void)
@@ -98,8 +125,10 @@
  The naming is chosen from the Win32 API (VirtualAlloc) which does the
  same thing and has done so forever, while support for this in Unix systems
  has only been added recently and is hidden in the posix portability mess.
- It is confusing because to get the reserve behavior we need MAP_NORESERVE
- (which tells the kernel not to allocate backing space), but heh...
+ The Linux manpage suggests that mmap must be passed MAP_NORESERVE in order
+ to get reservation-only behavior. It is confusing because to get the reserve
+ behavior we need MAP_NORESERVE (which tells the kernel not to allocate backing
+ space), but heh...
 */
 enum
 {
@@ -108,6 +137,44 @@
     MEM_RESERVE_AND_COMMIT = MEM_RESERVE | MEM_COMMIT
 };

+#if defined(linux_HOST_OS)
+static void *
+linux_retry_mmap(int operation, W_ size, void *ret, void *addr, int prot, int flags)
+{
+    if (addr != 0 && (operation & MEM_RESERVE)) {
+        // Try again with no hint address.
+        // It's not clear that this can ever actually help,
+        // but since our alternative is to abort, we may as well try.
+        ret = mmap(0, size, prot, flags, -1, 0);
+    }
+    if (ret == MAP_FAILED && errno == EPERM) {
+        // Linux is not willing to give us any mapping,
+        // so treat this as an out-of-memory condition
+        // (really out of virtual address space).
+        errno = ENOMEM;
+    }
+    return ret;
+}
+#endif /* defined(linux_HOST_OS) */
+
+static void
+post_mmap_madvise(int operation, W_ size, void *ret)
+{
+#if defined(MADV_WILLNEED)
+    if (operation & MEM_COMMIT) {
+        madvise(ret, size, MADV_WILLNEED);
+# if defined(MADV_DODUMP)
+        madvise(ret, size, MADV_DODUMP);
+# endif
+    } else {
+        madvise(ret, size, MADV_DONTNEED);
+# if defined(MADV_DONTDUMP)
+        madvise(ret, size, MADV_DONTDUMP);
+# endif
+    }
+#endif
+}
+
 /* Returns NULL on failure; errno set */
 static void *
 my_mmap (void *addr, W_ size, int operation)
@@ -149,69 +216,44 @@
                    VM_PROT_READ|VM_PROT_WRITE);
     }

-#else
+#else /* defined(darwin_HOST_OS) */

     int prot, flags;
-    if (operation & MEM_COMMIT)
+    if (operation & MEM_COMMIT) {
         prot = PROT_READ | PROT_WRITE;
-    else
+    } else {
         prot = PROT_NONE;
-    if (operation == MEM_RESERVE)
-# if defined(MAP_NORESERVE)
-        flags = MAP_NORESERVE;
+    }
+
+    if (operation == MEM_RESERVE) {
+# if defined(RESERVE_FLAGS)
+        flags = RESERVE_FLAGS;
 # else
-#  if defined(USE_LARGE_ADDRESS_SPACE)
-#   error USE_LARGE_ADDRESS_SPACE needs MAP_NORESERVE
-#  endif
         errorBelch("my_mmap(,,MEM_RESERVE) not supported on this platform");
 # endif
-    else if (operation == MEM_COMMIT)
-        flags = MAP_FIXED;
-    else
-        flags = 0;
+    } else if (operation == MEM_COMMIT) {
+        flags = MAP_FIXED | MAP_ANON | MAP_PRIVATE;
+    } else {
+        flags = MAP_ANON | MAP_PRIVATE;
+    }

-#if defined(hpux_HOST_OS)
-    ret = mmap(addr, size, prot, flags | MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
-#elif defined(linux_HOST_OS)
-    ret = mmap(addr, size, prot, flags | MAP_ANON | MAP_PRIVATE, -1, 0);
-    if (ret == (void *)-1 && errno == EPERM) {
+    ret = mmap(addr, size, prot, flags, -1, 0);
+# if defined(linux_HOST_OS)
+    if (ret == MAP_FAILED && errno == EPERM) {
         // Linux may return EPERM if it tried to give us
         // a chunk of address space below mmap_min_addr,
         // See Trac #7500.
-        if (addr != 0 && (operation & MEM_RESERVE)) {
-            // Try again with no hint address.
-            // It's not clear that this can ever actually help,
-            // but since our alternative is to abort, we may as well try.
-            ret = mmap(0, size, prot, flags | MAP_ANON | MAP_PRIVATE, -1, 0);
-        }
-        if (ret == (void *)-1 && errno == EPERM) {
-            // Linux is not willing to give us any mapping,
-            // so treat this as an out-of-memory condition
-            // (really out of virtual address space).
-            errno = ENOMEM;
-        }
+        ret = linux_retry_mmap(operation, size, ret, addr, prot, flags);
     }
-
-    if (operation & MEM_COMMIT) {
-        madvise(ret, size, MADV_WILLNEED);
-#if defined(MADV_DODUMP)
-        madvise(ret, size, MADV_DODUMP);
-#endif
-    } else {
-        madvise(ret, size, MADV_DONTNEED);
-#if defined(MADV_DONTDUMP)
-        madvise(ret, size, MADV_DONTDUMP);
-#endif
-    }
-
-#else
-    ret = mmap(addr, size, prot, flags | MAP_ANON | MAP_PRIVATE, -1, 0);
-#endif
-#endif
-
-    if (ret == (void *)-1) {
+# endif
+    if (ret == MAP_FAILED) {
         return NULL;
     }
+#endif /* defined(darwin_HOST_OS) */
+
+    // Map in committed pages rather than take a fault for each chunk.
+    // Also arrange to include them in core-dump files.
+    post_mmap_madvise(operation, size, ret);

     return ret;
 }
@@ -435,6 +477,8 @@
     void *base, *top;
     void *start, *end;

+    ASSERT((len & ~MBLOCK_MASK) == len);
+
     /* We try to allocate len + MBLOCK_SIZE,
        because we need memory which is MBLOCK_SIZE aligned,
        and then we discard what we don't need */
@@ -500,8 +544,19 @@
             (void*)startAddress, (void*)minimumAddress);
     }

+#if defined(HAVE_SYS_RESOURCE_H) && defined(HAVE_SYS_TIME_H)
+    struct rlimit limit;
+    if (!getrlimit(RLIMIT_AS, &limit)
+        && limit.rlim_cur > 0
+        && *len > limit.rlim_cur) {
+        *len = limit.rlim_cur;
+    }
+#endif
+
     attempt = 0;
     while (1) {
+        *len &= ~MBLOCK_MASK;
+
         if (*len < MBLOCK_SIZE) {
             // Give up if the system won't even give us 16 blocks worth of heap
             barf("osReserveHeapMemory: Failed to allocate heap storage");
@@ -512,9 +567,14 @@
         if (at == NULL) {
             // This means that mmap failed which we take to mean that we asked
             // for too much memory. This can happen due to POSIX resource
-            // limits. In this case we reduce our allocation request by a factor
-            // of two and try again.
-            *len /= 2;
+            // limits. In this case we reduce our allocation request by a
+            // fraction of the current size and try again.
+            //
+            // Note that the previously would instead decrease the request size
+            // by a factor of two; however, this meant that significant amounts
+            // of memory will be wasted (e.g. imagine a machine with 512GB of
+            // physical memory but a 511GB ulimit). See #14492.
+            *len -= *len / 8;
         } else if ((W_)at >= minimumAddress) {
             // Success! We were given a block of memory starting above the 8 GB
             // mark, which is what we were looking for.
@@ -536,7 +596,7 @@
 {
     void *r = my_mmap(at, size, MEM_COMMIT);
     if (r == NULL) {
-        barf("Unable to commit %d bytes of memory", size);
+        barf("Unable to commit %" FMT_Word " bytes of memory", size);
     }
 }
