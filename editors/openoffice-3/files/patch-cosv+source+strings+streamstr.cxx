--- ../cosv/source/strings/streamstr.cxx.orig	Tue Aug 13 14:29:52 2002
+++ ../cosv/source/strings/streamstr.cxx	Fri Oct 18 20:20:41 2002
@@ -65,7 +65,7 @@
 // NOT FULLY DECLARED SERVICES
 #include <string.h>
 #include <stdio.h>
-#if defined(WNT) || defined(LINUX) || defined(MACOSX)
+#if defined(WNT) || defined(LINUX) || defined(MACOSX) || defined(FREEBSD)
 #include <stdarg.h>
 #else
 #include <sys/varargs.h>
