
$FreeBSD$

--- src/System.hpp	2001/01/22 21:09:51	1.1
+++ src/System.hpp	2001/01/22 21:10:27
@@ -9,7 +9,7 @@
 #include "AmpHead.hpp"
 
 extern "C" {
-#include <SDL/SDL.h>
+#include <SDL.h>
 }
 
 #ifndef INSTALL_DIR
