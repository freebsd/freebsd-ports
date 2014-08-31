--- base/runtime/c-libs/posix-os/tmpname.c.orig	2000-06-01 20:34:03.000000000 +0200
+++ base/runtime/c-libs/posix-os/tmpname.c	2014-08-01 16:35:28.000000000 +0200
@@ -4,8 +4,11 @@
  */
 
 #include <stdio.h>
+#include <string.h>
+#include <unistd.h>
 #include "ml-base.h"
 #include "ml-values.h"
+#include "ml-c.h"
 #include "ml-objects.h"
 #include "cfun-proto-list.h"
 
@@ -13,9 +16,18 @@
  */
 ml_val_t _ml_OS_tmpname (ml_state_t *msp, ml_val_t arg)
 {
-    char	buf[L_tmpnam];
-
-    tmpnam (buf);
+    char	template[] = "/tmp/TMP-SMLNJ.XXXXXX";
+    char	buf[sizeof(template)];
+    int		fd;
+
+    strcpy (buf, template);
+
+    fd = mkstemp (buf);
+
+    if (fd == -1)
+	return RAISE_SYSERR(msp, -1);
+    else
+	close (fd);
 
     return ML_CString (msp, buf);
 
