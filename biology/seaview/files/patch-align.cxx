--- align.cxx.orig	Tue Oct  8 19:43:40 2002
+++ align.cxx	Mon Nov 18 11:40:08 2002
@@ -1,5 +1,6 @@
 #include "seaview.h"
 #include <stdlib.h>
+#include <unistd.h>
 #include <ctype.h>
 #ifndef WIN32
 #include <FL/x.H>
@@ -155,7 +156,7 @@
 #endif
 debut = view->active_region->list->debut;
 fin = view->active_region->list->fin;
-tmpnam(base_fname);
+mkstemp(base_fname);
 /* 
 convertir en minuscules car clustalw n'accepte pas les majuscules ds filenames
 */
