--- libs/pbd/stacktrace.cc.orig	Thu Mar 29 18:26:37 2007
+++ libs/pbd/stacktrace.cc	Thu Mar 29 18:27:27 2007
@@ -3,7 +3,9 @@
 
 /* Obtain a backtrace and print it to stdout. */
 
-#ifdef HAVE_EXECINFO
+/* Without this change, ardourvst dies during startup with
+   'wine: could not load L"Z:\\usr\\local\\lib\\ardour2\\ardour_vst.exe.so": Bad EXE format for''. */
+#if 0
 
 #include <execinfo.h>
 #include <stdlib.h>
