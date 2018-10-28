--- drumgizmo/output/oss.cc.orig	2018-10-06 16:27:27 UTC
+++ drumgizmo/output/oss.cc
@@ -30,6 +30,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <iostream>
+#include <cstring>
 
 
 OSSOutputEngine::OSSOutputEngine()
