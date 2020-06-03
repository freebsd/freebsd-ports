--- cmake/modules/c_flags.cmake.orig	2020-05-31 22:00:20 UTC
+++ cmake/modules/c_flags.cmake
@@ -30,6 +30,7 @@ add_cflag_if_supported("-Wmaybe-uninitialized")
 add_cflag_if_supported("-Wmissing-variable-declarations")
 add_cflag_if_supported("-Wshorten-64-to-32")
 add_cflag_if_supported("-Wimplicit-function-declaration")
+add_cflag_if_supported("-Wno-string-plus-int")
 
 ##
 # On OpenBSD the system headers suck so we need to disable redundant declaration check
