--- cmake/Modules/WaffleValidateOptions.cmake.orig	2015-01-22 20:00:17 UTC
+++ cmake/Modules/WaffleValidateOptions.cmake
@@ -44,7 +44,7 @@ if(DEFINED waffle_install_docdir)
             "details.")
 endif()
 
-if(waffle_on_linux)
+if(waffle_on_linux OR waffle_on_freebsd)
     if(NOT waffle_has_glx AND NOT waffle_has_wayland AND
        NOT waffle_has_x11_egl AND NOT waffle_has_gbm)
         message(FATAL_ERROR
