--- ./Shisensho/src/LLKPanelController.cpp.orig	2008-03-19 12:20:04.000000000 +0100
+++ ./Shisensho/src/LLKPanelController.cpp	2013-12-27 20:07:09.043178203 +0100
@@ -19,6 +19,7 @@
 //Contact us at ggwizard@gmail.com or darkdong@gmail.com.
 //****************************************************************************/
 
+#include <time.h>
 #include "LLKPanelController.h"
 #include "LLKDesktopController.h"
 #include "DJGameController.h"
@@ -61,4 +62,4 @@
 		break;
 	}
 	DJPanelController::gameTrace(gameTrace);
-}
\ No newline at end of file
+}
