--- align.cxx.orig	Mon Nov 17 14:15:01 2003
+++ align.cxx	Mon Nov 17 14:15:26 2003
@@ -1,6 +1,7 @@
 #include "seaview.h"
 #include <stdlib.h>
 #include <ctype.h>
+#include <unistd.h>
 #ifndef WIN32
 #include <FL/x.H>
 #endif
@@ -155,7 +156,7 @@
 #endif
 debut = view->active_region->list->debut;
 fin = view->active_region->list->fin;
-tmpnam(base_fname);
+mkstemp(base_fname);
 /* 
 convertir en minuscules car clustalw n'accepte pas les majuscules ds filenames
 */
