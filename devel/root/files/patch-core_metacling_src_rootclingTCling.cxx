--- core/metacling/src/rootclingTCling.cxx.orig	2022-11-16 10:35:46 UTC
+++ core/metacling/src/rootclingTCling.cxx
@@ -20,6 +20,11 @@
 
 #undef R__DLLEXPORT
 
+#ifdef __FreeBSD__
+char *__progname;
+char **environ;
+#endif
+
 #include "TROOT.h"
 #include "TCling.h"
 
