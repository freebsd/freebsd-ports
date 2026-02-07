--- libexplain/vasprintf.h.orig	2013-12-06 17:16:42.000000000 +0900
+++ libexplain/vasprintf.h	2013-12-06 17:17:29.000000000 +0900
@@ -27,6 +27,8 @@
   * by the <i>vasprintf</i>(3) system call.
   */
 
+#include <libexplain/ac/stdarg.h>
+
 #include <libexplain/gcc_attributes.h>
 #include <libexplain/large_file_support.h>
 
