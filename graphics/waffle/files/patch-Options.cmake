diff --git Options.cmake Options.cmake
index 7f694e3..8fa62dd 100644
--- Options.cmake
+++ Options.cmake
@@ -1,4 +1,4 @@
-if(waffle_on_linux)
+if(waffle_on_linux OR waffle_on_freebsd)
     # On Linux, you must enable at least one of the below options.
     option(waffle_has_glx "Build support for GLX" OFF)
     option(waffle_has_wayland "Build support for Wayland" OFF)
