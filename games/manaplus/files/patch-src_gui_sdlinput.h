--- src/gui/sdlinput.h.orig	2013-11-12 08:07:13.000000000 +0100
+++ src/gui/sdlinput.h	2013-11-12 08:07:56.000000000 +0100
@@ -61,6 +61,8 @@
 
 #include "input/keyinput.h"
 
+#include "mouseinput.h"
+
 #include <SDL_events.h>
 
 #include <guichan/input.hpp>
@@ -69,8 +71,6 @@
 
 #include <queue>
 
-class MouseInput;
-
 namespace Key
 {
     enum
