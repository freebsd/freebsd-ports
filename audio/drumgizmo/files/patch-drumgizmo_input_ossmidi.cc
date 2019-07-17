--- drumgizmo/input/ossmidi.cc.orig	2019-05-08 15:53:39 UTC
+++ drumgizmo/input/ossmidi.cc
@@ -30,6 +30,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <iostream>
+#include <cstring>
 
 
 OSSInputEngine::OSSInputEngine()
