--- src/general.pri.orig	2020-05-02 21:17:23 UTC
+++ src/general.pri
@@ -9,7 +9,7 @@
 DEFINES += MESHLAB_SCALAR=float
 
 # VCG directory
-VCGDIR = $$MESHLAB_SOURCE_DIRECTORY/../vcglib
+VCGDIR = %%LOCALBASE%%/include/vcglib
 
 include(find_system_libs.pri)
 
