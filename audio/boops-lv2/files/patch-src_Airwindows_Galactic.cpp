-- add missing include for rand() function
-- https://github.com/sjaehn/BOops/issues/27

--- src/Airwindows/Galactic.cpp.orig	2026-05-21 06:44:26 UTC
+++ src/Airwindows/Galactic.cpp
@@ -28,6 +28,8 @@
  */
 
 #include "Galactic.hpp"
+#include <stdlib.h> // for rand()
+
 
 Galactic::Galactic () : Galactic (48000, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f) {}
 
