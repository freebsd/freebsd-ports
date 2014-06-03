--- CMakeModules/FindBazaar.cmake.orig	2014-06-03 10:50:21.643697284 +0200
+++ CMakeModules/FindBazaar.cmake	2014-06-03 10:56:17.490476480 +0200
@@ -52,4 +52,5 @@
     set( _Bazaar_SAVED_LC_ALL "$ENV{LC_ALL}" )
     set( ENV{LC_ALL} C )
+    set(ENV{BZR_LOG} "/dev/null")
 
     # Fetch the Bazaar executable version.
