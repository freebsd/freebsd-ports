--- dlls/ntdll/unix/system.c.orig	2026-08-03 08:08:29 UTC
+++ dlls/ntdll/unix/system.c
@@ -765,6 +765,7 @@ void init_shared_data_cpuinfo( KUSER_SHARED_DATA *data
 
 #endif /* End architecture specific feature detection for CPUs */
 
+#ifdef __linux__
 static void fill_performance_core_info(void);
 static BOOL sysfs_parse_bitmap(const char *filename, ULONG_PTR *mask);
 
@@ -974,6 +975,12 @@ error:
     cpu_override.mapping.cpu_count = 0;
     ERR("Invalid WINE_CPU_TOPOLOGY string %s (%s).\n", debugstr_a(env_override), debugstr_a(s));
 }
+#else
+void fill_cpu_override(void)
+{
+    /* do nothing */
+}
+#endif
 
 struct cpu_topology_override *get_cpu_topology_override(void)
 {
@@ -1674,6 +1681,98 @@ static NTSTATUS create_logical_proc_info(void)
     }
 
     /* OSX doesn't support NUMA, so just make one NUMA node for all CPUs */
+    if(!logical_proc_info_add_numa_node( all_cpus_mask, 0 ))
+        return STATUS_NO_MEMORY;
+
+    logical_proc_info_add_group( lcpu_no, all_cpus_mask );
+
+    return STATUS_SUCCESS;
+}
+
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+
+/*
+ * this is currently mostly a reduced clone of the macos implementation
+ * it only reports thread counts so that cb2077 don't spawn a single dispatch thread only, and would spawn #threads instead
+ * TODO list:
+ *   smt information
+ *   numa information
+ *   cache information
+ *   package count
+ * it is also tempting to rely on lscpu output, however that would make freebsd wine packaging dependent on lscpu, don't know if that's a good idea
+ * or perhaps go for cpuid directly? however that'd would introduce quite the amount of boiler plates
+ * yet another alternative would be to rely on /compat/linux/sys, however FreeBSD only lists the number of online cores without smt, numa, cache nor package information, and linux compat has to be enabled
+ */
+static NTSTATUS create_logical_proc_info(void)
+{
+    unsigned int pkgs_no, cores_no, lcpu_no, lcpu_per_core, cores_per_package;
+    ULONG_PTR all_cpus_mask = 0;
+    unsigned int i, p, j, k;
+    CACHE_DESCRIPTOR cache[10];
+
+    /* HW_NCPU works in FreeBSD */
+    lcpu_no = peb->NumberOfProcessors;
+
+    /* TODO assume one package */
+    pkgs_no = 1;
+
+    /* TODO assume no SMT */
+    /* physical core number can be fetch with sysctl kern.smp.cores */
+    cores_no = lcpu_no;
+
+    TRACE("%u logical CPUs from %u physical cores across %u packages\n",
+            lcpu_no, cores_no, pkgs_no);
+
+    lcpu_per_core = lcpu_no / cores_no;
+    cores_per_package = cores_no / pkgs_no;
+
+    for(p = 0; p < pkgs_no; ++p)
+    {
+        for(j = 0; j < cores_per_package && p * cores_per_package + j < cores_no; ++j)
+        {
+            ULONG_PTR mask = 0;
+            DWORD phys_core;
+
+            for(k = 0; k < lcpu_per_core; ++k) mask |= (ULONG_PTR)1 << (j * lcpu_per_core + k);
+
+            all_cpus_mask |= mask;
+
+            /* add to package */
+            if(!logical_proc_info_add_by_id( RelationProcessorPackage, p, mask ))
+                return STATUS_NO_MEMORY;
+
+            /* add new core */
+            phys_core = p * cores_per_package + j;
+            if(!logical_proc_info_add_by_id( RelationProcessorCore, phys_core, mask ))
+                return STATUS_NO_MEMORY;
+        }
+    }
+
+    /* TODO cache information */
+    memset(cache, 0, sizeof(cache));
+    cache[1].Level = 1;
+    cache[1].Type = CacheInstruction;
+    cache[1].Associativity = 8; /* reasonable default */
+    cache[1].LineSize = 0x40; /* reasonable default */
+    cache[2].Level = 1;
+    cache[2].Type = CacheData;
+    cache[2].Associativity = 8;
+    cache[2].LineSize = 0x40;
+    cache[3].Level = 2;
+    cache[3].Type = CacheUnified;
+    cache[3].Associativity = 8;
+    cache[3].LineSize = 0x40;
+    cache[4].Level = 3;
+    cache[4].Type = CacheUnified;
+    cache[4].Associativity = 12;
+    cache[4].LineSize = 0x40;
+    for(i = 0; i < 5; i++)
+    {
+        if(!logical_proc_info_add_cache( all_cpus_mask, &cache[i] ))
+            return STATUS_NO_MEMORY;
+    }
+
+    /* TODO numa infomration */
     if(!logical_proc_info_add_numa_node( all_cpus_mask, 0 ))
         return STATUS_NO_MEMORY;
 
