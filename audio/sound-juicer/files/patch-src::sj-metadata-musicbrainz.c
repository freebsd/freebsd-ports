--- src/sj-metadata-musicbrainz.c.orig	Mon Jan 17 13:22:54 2005
+++ src/sj-metadata-musicbrainz.c	Mon Jan 17 13:23:02 2005
@@ -18,7 +18,6 @@
  * Boston, MA 02111-1307, USA.
  */
 
-#include "sound-juicer.h"
 
 #include <string.h>
 #include <glib-object.h>
@@ -32,6 +31,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 
+#include "sound-juicer.h"
 #include "sj-metadata-musicbrainz.h"
 #include "sj-structures.h"
 #include "sj-error.h"
