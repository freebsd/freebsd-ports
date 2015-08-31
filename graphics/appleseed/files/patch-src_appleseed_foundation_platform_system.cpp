--- src/appleseed/foundation/platform/system.cpp.orig	2015-06-13 09:38:53 UTC
+++ src/appleseed/foundation/platform/system.cpp
@@ -74,6 +74,14 @@
     #include <sys/types.h>
     #include <unistd.h>
 
+// Linux.
+#elif defined __FreeBSD__
+
+    #include <sys/types.h>
+    #include <sys/resource.h>
+    #include <sys/sysctl.h>
+    #include <unistd.h>
+
 // Other platforms.
 #else
 
@@ -421,6 +429,386 @@ uint64 System::get_process_virtual_memor
     return static_cast<uint64>(rss) * sysconf(_SC_PAGESIZE);
 }
 
+// ------------------------------------------------------------------------------------------------
+// FreeBSD.
+// ------------------------------------------------------------------------------------------------
+
+#elif defined __FreeBSD__ && (__x86_64__ || __i386__)
+
+// FreeBSD does not provide an API to query CPU cache information, so we'd
+// have to ask for it by ourselves...
+
+#define bit(n)          (1ul << (n))
+#define bitmask(h,l)    ((bit(h) | (bit(h) - 1)) & ~(bit(l) - 1))
+#define bitfield(x,h,l) (((x) & bitmask(h, l)) >> l)
+
+enum { L1D, L2, L3 };
+enum { eax, ebx, ecx, edx };
+
+// Since we only want to know cache size and line size, structure below is
+// very simplistic.  Initially, all caches have zero size (i.e. absent).
+static struct trivial_x86_cache
+{
+    size_t size;
+    size_t linesize;
+} mycaches[3];
+
+// %ebx is used to point to GOT (Global Offset Table) for PIC (Position
+// Independent Code) on 32-bit x86, so use %edi to preserve %ebx across
+// the call and %esi when passing CPUID arguments and return values.
+static inline void
+cpuid(uint32_t* data)
+{
+    asm("movl %%ebx, %%edi\n\t"
+        "movl %%esi, %%ebx\n\t"
+        "cpuid\n\t"
+        "movl %%ebx, %%esi\n\t"
+        "movl %%edi, %%ebx"
+      : "=a" (data[eax]),
+        "=S" (data[ebx]),
+        "=c" (data[ecx]),
+        "=d" (data[edx])
+      :  "a" (data[eax]),
+         "S" (data[ebx]),
+         "c" (data[ecx]),
+         "d" (data[edx])
+      : "%edi");
+}
+
+// For modern CPUs, we use Deterministic Cache Parameters (Function 04h) to
+// obtain the cache data.
+static void
+get_cache_info_deterministic(struct trivial_x86_cache *caches)
+{
+    uint32_t regs[4];
+
+    // Cycle up to ten possible caches to be extra sure
+    for (size_t i = 0; i < 10; i++)
+    {
+        regs[eax] = 4;
+        regs[ecx] = i;
+        cpuid(regs);
+
+        unsigned type = bitfield(regs[eax], 4, 0);
+        if (type == 0) break;    // no more caches, we're done
+        if (type == 2) continue; // ignore instruction caches
+
+        unsigned level = bitfield(regs[eax], 7, 5);
+        unsigned linesize = bitfield(regs[ebx], 11, 0) + 1;
+        unsigned sets = bitfield(regs[ecx], 31, 0) + 1;
+        unsigned associativity = bitfield(regs[ebx], 31, 22) + 1;
+
+        assert(level > 0);
+
+        caches[level - 1].size = linesize * sets * associativity;
+        caches[level - 1].linesize = linesize;
+    }
+}
+
+// On older CPUs we might have to rely on Cache Descriptors (Function 02h)
+// and Intel documentation (table of the known values).
+static void
+get_cache_info_from_table(struct trivial_x86_cache *caches)
+{
+    uint32_t regs[4];
+    int no_higher_level_cache = 0;
+
+    regs[eax] = 2;
+    cpuid(regs);
+    // Doing only one call is technically wrong, but all CPUs
+    // up to Core i7 require a single call.  Since this is a
+    // fallback code path for really old CPUs anyways (modern
+    // ones will provide Function 4), we should be safe, but
+    // let's add an assert() on the lower 8 bits just in case.
+
+    assert ((regs[eax] & 0xFF) == 1);
+
+    for (size_t i = 1; i < 4 * 4; i++)
+    {
+        // Check descriptor validity for every octet: if bit 31 is set,
+        // skip to next one.
+        if (i % 4 == 0 && (regs[i / 4] >> 31) == 1)
+        {
+            i += 4;
+            continue;
+        }
+
+        // Descriptor decode values from the Intel manual, Table 2-7
+        switch ((regs[i / 4] >> (i % 4) * 8) & 0xFF)
+        {
+        case 0x0A:
+            caches[L1D].size = 8;
+            caches[L1D].linesize = 32;
+            break;
+        case 0x0C:
+            caches[L1D].size = 16;
+            caches[L1D].linesize = 32;
+            break;
+        case 0x0D:
+        case 0x60:
+        case 0x67:
+            caches[L1D].size = 16;
+            caches[L1D].linesize = 64;
+            break;
+        case 0x21:
+        case 0x3C:
+        case 0x7A:
+            caches[L2].size = 256;
+            caches[L2].linesize = 64;
+            break;
+        case 0x22:
+        case 0xD0:
+            caches[L3].size = 512;
+            caches[L3].linesize = 64;
+            break;
+        case 0x23:
+        case 0xD1:
+        case 0xD6:
+            caches[L3].size = 1024;
+            caches[L3].linesize = 64;
+            break;
+        case 0x25:
+        case 0xD2:
+        case 0xD7:
+        case 0xE2:
+            caches[L3].size = 2048;
+            caches[L3].linesize = 64;
+            break;
+        case 0x29:
+        case 0x46:
+        case 0xD8:
+        case 0xE3:
+            caches[L3].size = 4096;
+            caches[L3].linesize = 64;
+            break;
+        case 0x2C:
+            caches[L1D].size = 32;
+            caches[L1D].linesize = 64;
+            break;
+        case 0x39:
+        case 0x3B:
+        case 0x79:
+            caches[L2].size = 128;
+            caches[L2].linesize = 64;
+            break;
+        case 0x3A:
+            caches[L2].size = 192;
+            caches[L2].linesize = 64;
+            break;
+        case 0x3D:
+            caches[L2].size = 384;
+            caches[L2].linesize = 64;
+            break;
+        case 0x3E:
+        case 0x7B:
+        case 0x7F:
+        case 0x86:
+            caches[L2].size = 512;
+            caches[L2].linesize = 64;
+            break;
+        case 0x40:
+            no_higher_level_cache = 1;
+            break;
+        case 0x41:
+            caches[L2].size = 128;
+            caches[L2].linesize = 32;
+            break;
+        case 0x42:
+        case 0x82:
+            caches[L2].size = 256;
+            caches[L2].linesize = 32;
+            break;
+        case 0x43:
+        case 0x83:
+            caches[L2].size = 512;
+            caches[L2].linesize = 32;
+            break;
+        case 0x44:
+            caches[L2].size = 1024;
+            caches[L2].linesize = 32;
+            break;
+        case 0x45:
+            caches[L2].size = 2048;
+            caches[L2].linesize = 32;
+            break;
+        case 0x47:
+        case 0x4B:
+        case 0xE4:
+            caches[L3].size = 8192;
+            caches[L3].linesize = 64;
+            break;
+        case 0x48:
+            caches[L2].size = 3072;
+            caches[L2].linesize = 64;
+            break;
+        case 0x49:
+            // TODO: check for Intel Xeon processor MP, Family 0Fh,
+            // Model 06h, because 0x49 means L3 cache (4MB, 16-way,
+            // 64-byte linesize) for this CPU.
+            caches[L2].size = 4096;
+            caches[L2].linesize = 64;
+            break;
+        case 0x4A:
+        case 0xDE:
+            caches[L3].size = 6 * 1024;
+            caches[L3].linesize = 64;
+            break;
+        case 0x4C:
+        case 0xEA:
+            caches[L3].size = 12 * 1024;
+            caches[L3].linesize = 64;
+            break;
+        case 0x4D:
+            caches[L3].size = 16 * 1024;
+            caches[L3].linesize = 64;
+            break;
+        case 0x4E:
+            caches[L2].size = 6 * 1024;
+            caches[L2].linesize = 64;
+            break;
+        case 0x66:
+            caches[L1D].size = 8;
+            caches[L1D].linesize = 64;
+            break;
+        case 0x68:
+            caches[L1D].size = 32;
+            caches[L1D].linesize = 64;
+            break;
+        case 0x78:
+        case 0x7C:
+            caches[L2].size = 1024;
+            caches[L2].linesize = 64;
+            break;
+        case 0x7D:
+            caches[L2].size = 2048;
+            caches[L2].linesize = 64;
+            break;
+        case 0x84:
+            caches[L2].size = 1024;
+            caches[L2].linesize = 32;
+            break;
+        case 0x85:
+            caches[L2].size = 2048;
+            caches[L2].linesize = 32;
+            break;
+        case 0x87:
+            caches[L2].size = 1024;
+            caches[L2].linesize = 64;
+            break;
+        case 0xDC:
+            caches[L3].size = 1536;
+            caches[L3].linesize = 64;
+            break;
+        case 0xDD:
+            caches[L3].size = 3 * 1024;
+            caches[L3].linesize = 64;
+            break;
+        case 0xEB:
+            caches[L3].size = 18 * 1024;
+            caches[L3].linesize = 64;
+            break;
+        case 0xEC:
+            caches[L3].size = 24 * 1024;
+            caches[L3].linesize = 64;
+            break;
+        }
+    }
+    // Convert Kbytes to bytes.
+    caches[L1D].size *= 1024;
+    caches[L2].size *= 1024;
+    caches[L3].size *= 1024;
+}
+
+static void
+x86_get_cache_basic_info(struct trivial_x86_cache *caches)
+{
+    uint32_t regs[4];
+
+    regs[eax] = 0;
+    cpuid(regs);
+    if (regs[eax] >= 4)
+        get_cache_info_deterministic(caches);
+    else if (regs[eax] >= 2)
+        get_cache_info_from_table(caches);
+}
+
+size_t System::get_l1_data_cache_size()
+{
+    // Here and below we'd check for L1D cache size: if it's initialized,
+    // it means that x86_get_cache_basic_info() was already called, and
+    // we don't have to do it again.
+    if (!mycaches[L1D].size)
+        x86_get_cache_basic_info(mycaches);
+    return mycaches[L1D].size;
+}
+
+size_t System::get_l1_data_cache_line_size()
+{
+    if (!mycaches[L1D].size)
+        x86_get_cache_basic_info(mycaches);
+    return mycaches[L1D].linesize;
+}
+
+size_t System::get_l2_cache_size()
+{
+    if (!mycaches[L1D].size)
+        x86_get_cache_basic_info(mycaches);
+    return mycaches[L2].size;
+}
+
+size_t System::get_l2_cache_line_size()
+{
+    if (!mycaches[L1D].size)
+        x86_get_cache_basic_info(mycaches);
+    return mycaches[L2].linesize;
+}
+
+size_t System::get_l3_cache_size()
+{
+    if (!mycaches[L1D].size)
+        x86_get_cache_basic_info(mycaches);
+    return mycaches[L3].size;
+}
+
+size_t System::get_l3_cache_line_size()
+{
+    if (!mycaches[L1D].size)
+        x86_get_cache_basic_info(mycaches);
+    return mycaches[L3].linesize;
+}
+
+uint64 System::get_total_physical_memory_size()
+{
+    const long pagesize = sysconf(_SC_PAGESIZE);
+    const long numpages = sysconf(_SC_PHYS_PAGES);
+
+    return static_cast<uint64>(pagesize) * numpages;
+}
+
+uint64 System::get_total_virtual_memory_size()
+{
+    quad_t swap;
+    size_t len = sizeof(swap);
+
+    const int result = sysctlbyname("vm.swap_total", &swap, &len, 0x0, 0);
+    assert(result == 0);
+
+    return get_total_physical_memory_size() + swap;
+}
+
+// curproc->p_stats->p_ru is updated on statclock tick and can be not very
+// granular (if called early in program's life, it can even yield zeros).
+// Reference: https://lists.freebsd.org/pipermail/freebsd-stable/2006-March/023262.html
+uint64 System::get_process_virtual_memory_size()
+{
+    struct rusage ru;
+
+    const int result = getrusage(RUSAGE_SELF, &ru);
+    assert(result == 0);
+
+    return static_cast<uint64>(ru.ru_maxrss) * 1024;
+}
+
 #endif
 
 }   // namespace foundation
