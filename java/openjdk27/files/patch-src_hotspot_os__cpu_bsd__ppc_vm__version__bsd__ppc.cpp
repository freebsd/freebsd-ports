--- src/hotspot/os_cpu/bsd_ppc/vm_version_bsd_ppc.cpp.orig  2026-09-03 11:42:54 UTC
+++ src/hotspot/os_cpu/bsd_ppc/vm_version_bsd_ppc.cpp
@@ -0,0 +1,46 @@
+/*
+ * Copyright (c) 2026, Piotr Kubaj. All rights reserved.
+ * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
+ *
+ * This code is free software; you can redistribute it and/or modify it
+ * under the terms of the GNU General Public License version 2 only, as
+ * published by the Free Software Foundation.
+ *
+ * This code is distributed in the hope that it will be useful, but WITHOUT
+ * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
+ * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
+ * version 2 for more details (a copy is included in the LICENSE file that
+ * accompanied this code).
+ *
+ * You should have received a copy of the GNU General Public License version
+ * 2 along with this work; if not, write to the Free Software Foundation,
+ * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
+ *
+ * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
+ * or visit www.oracle.com if you need additional information or have any
+ * questions.
+ *
+ */
+
+#include "runtime/vm_version.hpp"
+
+#include <sys/types.h>
+#include <sys/sysctl.h>
+
+// FreeBSD exposes a single PPC coherency block size covering both caches.
+static int cacheline_size() {
+  int size = 0;
+  size_t len = sizeof(size);
+  if (sysctlbyname("machdep.cacheline_size", &size, &len, nullptr, 0) != 0 || size <= 0) {
+    return DEFAULT_CACHE_LINE_SIZE;
+  }
+  return size;
+}
+
+int VM_Version::get_dcache_line_size() {
+  return cacheline_size();
+}
+
+int VM_Version::get_icache_line_size() {
+  return cacheline_size();
+}
