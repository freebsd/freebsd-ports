Use pugixml from ports, rather than embedded

--- es-core/src/InputConfig.h.orig	2018-08-11 01:03:59 UTC
+++ es-core/src/InputConfig.h
@@ -2,7 +2,7 @@
 #ifndef ES_CORE_INPUT_CONFIG_H
 #define ES_CORE_INPUT_CONFIG_H
 
-#include <pugixml/src/pugixml.hpp>
+#include <pugixml.hpp>
 #include <SDL_joystick.h>
 #include <SDL_keyboard.h>
 #include <map>
