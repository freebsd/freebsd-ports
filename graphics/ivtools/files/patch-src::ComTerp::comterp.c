--- src/ComTerp/comterp.c~	Tue May 25 15:07:38 2004
+++ src/ComTerp/comterp.c	Mon Nov 22 11:27:09 2004
@@ -63,6 +63,7 @@
 #if __GNUC__>=3
 #include <fstream.h>
 #endif
+#include <errno.h>
 
 #define TITLE "ComTerp"
 #define STREAM_MECH
