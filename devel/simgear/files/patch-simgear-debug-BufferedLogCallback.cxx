--- simgear/debug/BufferedLogCallback.cxx.orig	2014-10-27 09:26:46.499707738 +0100
+++ simgear/debug/BufferedLogCallback.cxx	2014-10-27 09:27:54.034557089 +0100
@@ -26,6 +26,8 @@
 #include <simgear/sg_inlines.h>
 #include <simgear/threads/SGThread.hxx>
 #include <simgear/threads/SGGuard.hxx>
+
+#include <cstdlib> // for malloc
      
 namespace simgear
 {
