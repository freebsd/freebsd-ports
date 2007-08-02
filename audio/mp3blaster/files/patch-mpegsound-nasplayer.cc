--- mpegsound/nasplayer.cc.orig	Thu Aug  2 16:08:09 2007
+++ mpegsound/nasplayer.cc	Thu Aug  2 16:08:35 2007
@@ -12,6 +12,7 @@
 #include "mpegsound.h"
 #include "mpegsound_locals.h"
 #include <unistd.h>
+#include <stdlib.h>
 
 NASplayer::NASplayer(AuServer *aud)
 {
