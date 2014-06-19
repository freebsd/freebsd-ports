--- CMakeModules/CreateBzrVersionHeader.cmake.orig	2014-06-03 10:53:29.733708471 +0200
+++ CMakeModules/CreateBzrVersionHeader.cmake	2014-06-03 10:58:06.974972851 +0200
@@ -30,4 +30,5 @@
         set( _Bazaar_SAVED_LC_ALL "$ENV{LC_ALL}" )
         set( ENV{LC_ALL} C )
+        set(ENV{BZR_LOG} "/dev/null")
 
         # Get the tree revison
