--- src/components/performance_counters/memory/mem_counter_freebsd.cpp.orig	2019-02-24 17:20:45 UTC
+++ src/components/performance_counters/memory/mem_counter_freebsd.cpp
@@ -0,0 +1,51 @@
+// Copyright (c) 2012 Yuri Victorovich
+
+// Distributed under the Boost Software License, Version 1.0. (See accompanying
+// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
+
+#if defined(__FreeBSD__)
+
+#include <unistd.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+
+#include <cstdint>
+
+namespace hpx { namespace performance_counters { namespace memory
+{
+
+    ///////////////////////////////////////////////////////////////////////////
+    // Returns virtual memory usage.
+    std::uint64_t read_psm_virtual(bool)
+    {
+        // TODO
+        return 0; // numVirtual * EXEC_PAGESIZE;
+    }
+
+    // Returns resident memory usage.
+    std::uint64_t read_psm_resident(bool)
+    {
+        // TODO
+        return 0; // numResident * EXEC_PAGESIZE;
+    }
+
+    // Returns total available memory
+    std::uint64_t read_total_mem_avail(bool)
+    {
+        size_t len;
+        int pagesize = getpagesize(), free_pages;
+        u_long total;
+
+        len = sizeof(total);
+        if (sysctlbyname("hw.physmem", &total, &len, NULL, 0) == -1)
+                total = 0;
+
+        total = total / 1024;
+
+        return total;
+    }
+
+}}}
+
+#endif
+
