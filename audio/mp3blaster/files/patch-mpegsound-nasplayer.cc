--- mpegsound/nasplayer.cc.orig	2009-01-18 16:52:25.000000000 +0300
+++ mpegsound/nasplayer.cc	2009-01-19 22:36:01.000000000 +0300
@@ -12,6 +12,7 @@
 #include "mpegsound.h"
 #include "mpegsound_locals.h"
 #include <unistd.h>
+#include <stdlib.h>
 
 NASplayer::NASplayer(AuServer *aud)
 {
