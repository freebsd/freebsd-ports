--- bibc/supervis/aster_utils.c.orig	2020-10-20 16:45:20.000000000 +0200
+++ bibc/supervis/aster_utils.c	2020-11-22 17:01:12.951054000 +0100
@@ -18,6 +18,8 @@
 
 /* person_in_charge: mathieu.courtois at edf.fr */
 
+#include <string.h>
+#define __STDC_WANT_LIB_EXT1__ 1
 #include "aster_utils.h"
 #include "aster_module.h"
 #include "aster_fort.h"
@@ -91,7 +93,9 @@
     /* Initialise un blanc une chaine de caractères (sans '\0' à la fin).
      * S'applique à une chaine allouée par le Fortran.
      */
-    memset(fstr, ' ', flen);
+    if (memset_s(fstr, flen, ' ', flen) != 0) {
+        MYABORT("Erreur sur memset_s");
+    }
 }
 
 char * MakeBlankFStr( _IN STRING_SIZE flen )
