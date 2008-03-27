diff -u -r1.7 mod_quotatab_sql.c
--- contrib/mod_quotatab_sql.c	23 Jun 2005 23:23:30 -0000	1.7
+++ contrib/mod_quotatab_sql.c	27 Mar 2008 01:42:58 -0000
@@ -2,7 +2,7 @@
  * ProFTPD: mod_quotatab_sql -- a mod_quotatab sub-module for managing quota
  *                              data via SQL-based tables
  *
- * Copyright (c) 2002-2003 TJ Saunders
+ * Copyright (c) 2002-2008 TJ Saunders
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
@@ -289,17 +289,36 @@
 
     /* Match names if need be */
     if (quota_type != ALL_QUOTA &&
-        values[0] && strlen(values[0]) && strcmp(name, quotatab_tally.name)) {
+        values[0] &&
+        strlen(values[0]) > 0 &&
+        strcmp(name, quotatab_tally.name) != 0) {
       destroy_pool(tmp_pool);
       return FALSE;
     }
 
-    quotatab_tally.bytes_in_used = atof(values[2]);
-    quotatab_tally.bytes_out_used = atof(values[3]);
-    quotatab_tally.bytes_xfer_used = atof(values[4]);
-    quotatab_tally.files_in_used = atoi(values[5]);
-    quotatab_tally.files_out_used = atoi(values[6]);
-    quotatab_tally.files_xfer_used = atoi(values[7]);
+    quotatab_tally.bytes_in_used = -1.0;
+    if (values[2])
+      quotatab_tally.bytes_in_used = atof(values[2]);
+
+    quotatab_tally.bytes_out_used = -1.0;
+    if (values[3])
+      quotatab_tally.bytes_out_used = atof(values[3]);
+
+    quotatab_tally.bytes_xfer_used = -1.0;
+    if (values[4])
+      quotatab_tally.bytes_xfer_used = atof(values[4]);
+
+    quotatab_tally.files_in_used = 0;
+    if (values[5])
+      quotatab_tally.files_in_used = atol(values[5]);
+
+    quotatab_tally.files_out_used = 0;
+    if (values[6])
+      quotatab_tally.files_out_used = atol(values[6]);
+
+    quotatab_tally.files_xfer_used = 0;
+    if (values[7])
+      quotatab_tally.files_xfer_used = atol(values[7]);
 
     destroy_pool(tmp_pool);
     return TRUE;
@@ -368,12 +387,29 @@
     else if (strcasecmp(values[3], "hard") == 0)
       quotatab_limit.quota_limit_type = HARD_LIMIT;
 
-    quotatab_limit.bytes_in_avail = atof(values[4]);
-    quotatab_limit.bytes_out_avail = atof(values[5]);
-    quotatab_limit.bytes_xfer_avail = atof(values[6]);
-    quotatab_limit.files_in_avail = atol(values[7]);
-    quotatab_limit.files_out_avail = atol(values[8]);
-    quotatab_limit.files_xfer_avail = atol(values[9]);
+    quotatab_limit.bytes_in_avail = -1.0;
+    if (values[4])
+      quotatab_limit.bytes_in_avail = atof(values[4]);
+
+    quotatab_limit.bytes_out_avail = -1.0;
+    if (values[5])
+      quotatab_limit.bytes_out_avail = atof(values[5]);
+
+    quotatab_limit.bytes_xfer_avail = -1.0;
+    if (values[6])
+      quotatab_limit.bytes_xfer_avail = atof(values[6]);
+
+    quotatab_limit.files_in_avail = 0;
+    if (values[7])
+      quotatab_limit.files_in_avail = atol(values[7]);
+
+    quotatab_limit.files_out_avail = 0;
+    if (values[8])
+      quotatab_limit.files_out_avail = atol(values[8]);
+
+    quotatab_limit.files_xfer_avail = 0;
+    if (values[9])
+      quotatab_limit.files_xfer_avail = atol(values[9]);
 
     destroy_pool(tmp_pool);
     return TRUE;
