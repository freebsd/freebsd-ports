--- creation.c Thu Aug  3 22:29:37 1995
+++ /home/andy/tmp/wrk/creation.c      Wed Dec  2 21:02:24 1998
@@ -1,7 +1,11 @@
 #include "creation.h"
 #include "game.h"
 
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 
 void CreateUniverse(Univers *U, int NbNiveaux, int Taille)
 {
