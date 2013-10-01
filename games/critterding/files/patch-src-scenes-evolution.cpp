--- src/scenes/evolution.cpp.orig	2010-03-06 01:14:29.000000000 +0300
+++ src/scenes/evolution.cpp	2013-09-30 06:53:44.815518897 +0400
@@ -1,6 +1,4 @@
-#ifdef _WIN32
-	#include <unistd.h>
-#endif
+#include <unistd.h>
 #include "evolution.h"
 
 # include <math.h>
@@ -287,7 +285,7 @@
 					}
 					else if ( world->mouseRayHitEntity->type == 0 )
 					{
-						CritterB* c = static_cast<const CritterB*>(world->mouseRayHitEntity);
+						const CritterB* c = static_cast<const CritterB*>(world->mouseRayHitEntity);
 						Textprinter::Instance()->print( oldx+margin, oldy,    "critter");
 						Textprinter::Instance()->print(oldx+rmargindistance, oldy, "%1i", c->critterID);
 						Textprinter::Instance()->print( oldx+margin, oldy+vspacer, "energy");
