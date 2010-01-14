Index: include/yukon.h
===================================================================
--- include/yukon.h	(revision 158)
+++ include/yukon.h	(working copy)
@@ -2,8 +2,10 @@
 #ifndef __YUKON_H__
 #define __YUKON_H__
 
+#include <sys/param.h>
+#include <sys/limits.h>
+
 #include <stdarg.h>
-#include <linux/limits.h>
 
 #include <seom/seom.h>
 
