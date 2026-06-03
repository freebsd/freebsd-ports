--- src/she/sdl2/she.cpp.orig	2025-09-29 05:30:09 UTC
+++ src/she/sdl2/she.cpp
@@ -39,6 +39,8 @@
 #include <chrono>
 #include <thread>
 
+#undef None // see https://github.com/LibreSprite/LibreSprite/issues/563
+
 float penPressure = 0;
 
 namespace ui {
