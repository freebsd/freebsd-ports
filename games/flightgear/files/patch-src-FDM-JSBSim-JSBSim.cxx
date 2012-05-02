--- src/FDM/JSBSim/JSBSim.cxx.orig	2012-04-30 11:31:18.119554386 +0300
+++ src/FDM/JSBSim/JSBSim.cxx	2012-04-30 11:31:38.251553602 +0300
@@ -28,7 +28,7 @@
 #include <simgear/compiler.h>
 #include <simgear/sg_inlines.h>
 
-#include <stdio.h>    //    size_t
+#include <cstdlib>    //    size_t
 #include <string>
 
 #include <simgear/constants.h>

