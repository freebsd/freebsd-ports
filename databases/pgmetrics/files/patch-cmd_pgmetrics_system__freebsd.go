--- /dev/null	2018-03-06 12:20:46.000000000 +0100
+++ cmd/pgmetrics/system_freebsd.go	2018-03-06 12:18:41.362207000 +0100
@@ -0,0 +1,21 @@
+/*
+ * Copyright 2018 RapidLoop, Inc.
+ *
+ * Licensed under the Apache License, Version 2.0 (the "License");
+ * you may not use this file except in compliance with the License.
+ * You may obtain a copy of the License at
+ *
+ *     http://www.apache.org/licenses/LICENSE-2.0
+ *
+ * Unless required by applicable law or agreed to in writing, software
+ * distributed under the License is distributed on an "AS IS" BASIS,
+ * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
+ * See the License for the specific language governing permissions and
+ * limitations under the License.
+ */
+
+package main
+
+func (c *collector) collectSystem(o options) {
+	// Not implemented for FreeBSD yet.
+}
