--- cmake/CFlags.cmake.orig	2017-07-01 17:41:54.000000000 +0300
+++ cmake/CFlags.cmake	2017-08-21 18:28:07.994387000 +0300
@@ -27,6 +27,7 @@ add_cflag_if_supported("-Wmaybe-uninitia
 add_cflag_if_supported("-Wmissing-variable-declarations")
 add_cflag_if_supported("-Wshorten-64-to-32")
 add_cflag_if_supported("-Wimplicit-function-declaration")
+add_cflag_if_supported("-Wno-string-plus-int")
 
 ##
 # On OpenBSD the system headers suck so we need to disable redundant declaration check
