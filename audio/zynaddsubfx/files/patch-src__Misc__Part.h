--- src/Misc/Part.h~	2013-10-22 18:39:58.000000000 +0300
+++ src/Misc/Part.h	2013-10-22 18:40:09.000000000 +0300
@@ -30,6 +30,7 @@
 #include "../Misc/Microtonal.h"
 
 #include <list> // For the monomemnotes list.
+#include <pthread.h>
 
 class EffectMgr;
 class ADnoteParameters;
