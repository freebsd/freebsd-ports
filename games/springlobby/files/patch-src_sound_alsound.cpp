--- src/sound/alsound.cpp.orig	2020-10-31 09:53:52 UTC
+++ src/sound/alsound.cpp
@@ -13,7 +13,7 @@
 #define ALURE_STATIC_LIBRARY
 #endif
 
-#include <alure.h>
+#include <AL/alure.h>
 #include <assert.h>
 #include <lslutils/globalsmanager.h>
 #include <wx/log.h>
