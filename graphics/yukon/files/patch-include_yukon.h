--- include/yukon.h.orig	2007-06-07 13:30:34 UTC
+++ include/yukon.h
@@ -2,8 +2,10 @@
 #ifndef __YUKON_H__
 #define __YUKON_H__
 
+#include <sys/param.h>
+#include <sys/limits.h>
+
 #include <stdarg.h>
-#include <linux/limits.h>
 
 #include <seom/seom.h>
 
