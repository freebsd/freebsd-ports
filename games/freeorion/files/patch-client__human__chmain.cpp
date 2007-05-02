--- ./client/human/chmain.cpp.orig	Sun Apr 22 23:44:35 2007
+++ ./client/human/chmain.cpp	Sun Apr 29 18:37:23 2007
@@ -1,4 +1,4 @@
-#include "HumanClientAppSoundFMOD.h"
+#include "HumanClientAppSoundOpenAL.h"
 #include "../../util/OptionsDB.h"
 #include "../../util/Directories.h"
 #include "../../util/XMLDoc.h"
@@ -60,7 +60,7 @@
         return 1;
     }
 
-    HumanClientAppSoundFMOD app;
+    HumanClientAppSoundOpenAL app;
 
     try {
         app(); // run app (intialization and main process loop)
