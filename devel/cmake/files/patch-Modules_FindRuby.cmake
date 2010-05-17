--- Modules/FindRuby.cmake.orig	2010-05-16 23:37:17.000000000 +0200
+++ Modules/FindRuby.cmake	2010-05-16 23:37:30.000000000 +0200
@@ -193,7 +193,7 @@
 
 
 # Determine the list of possible names for the ruby library
-SET(_RUBY_POSSIBLE_LIB_NAMES ruby ruby-static ruby${_RUBY_VERSION_SHORT})
+SET(_RUBY_POSSIBLE_LIB_NAMES ruby ruby-static ruby${_RUBY_VERSION_SHORT} ruby${_RUBY_VERSION_SHORT_NODOT})
 
 IF(WIN32)
    SET( _RUBY_MSVC_RUNTIME "" )


