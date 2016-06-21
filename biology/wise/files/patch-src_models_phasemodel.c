--- src/models/phasemodel.c.orig	2007-09-08 08:05:32 UTC
+++ src/models/phasemodel.c
@@ -3,6 +3,10 @@ extern "C" {
 #endif
 #include "phasemodel.h"
 
+#ifdef __DragonFly__
+#define isnumber	isdigit
+#endif
+
 # line 59 "phasemodel.dy"
 ProteinIntronList * read_ProteinIntronList(FILE * ifp)
 {
