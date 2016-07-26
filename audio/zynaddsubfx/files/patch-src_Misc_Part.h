--- src/Misc/Part.h.orig	2012-06-14 14:35:03 UTC
+++ src/Misc/Part.h
@@ -30,6 +30,7 @@
 #include "../Misc/Microtonal.h"
 
 #include <list> // For the monomemnotes list.
+#include <pthread.h>
 
 class EffectMgr;
 class ADnoteParameters;
