--- src/file_list.c.old	Sat Mar 31 11:27:00 2001
+++ src/file_list.c	Sat Mar 31 11:37:38 2001
@@ -186,7 +186,11 @@
     /* do a glob() */
     memset(&glob_buf, 0, sizeof(glob_buf));
     glob_ret = glob(pattern, GLOB_ERR, NULL, &glob_buf);
+#ifndef GLOB_NOMATCH /* FreeBSD rocks your world */
+    if (glob_ret == GLOB_NOCHECK) {
+#else
     if (glob_ret == GLOB_NOMATCH) {
+#endif
         fdprintf(out, "total 0\r\n");
         return 1;
     } else if (glob_ret == GLOB_NOSPACE) {
