--- ../cosv/source/strings/streamstr.cxx.orig	Mon Jul 15 14:49:31 2002
+++ ../cosv/source/strings/streamstr.cxx	Mon Jul 15 14:49:33 2002
@@ -65,7 +65,7 @@
 // NOT FULLY DECLARED SERVICES
 #include <string.h>
 #include <stdio.h>
-#if defined(WNT) || defined(LINUX)
+#if defined(WNT) || defined(LINUX) || defined(FREEBSD)
 #include <stdarg.h>
 #else
 #include <sys/varargs.h>
