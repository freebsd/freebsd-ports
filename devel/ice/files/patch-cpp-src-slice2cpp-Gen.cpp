--- cpp.orig/src/slice2cpp/Gen.cpp	2013-03-11 15:19:46.000000000 +0000
+++ cpp/src/slice2cpp/Gen.cpp	2013-05-20 19:51:48.109197053 +0000
@@ -385,6 +385,10 @@
         H << "\n#include <Ice/Proxy.h>";
         H << "\n#include <Ice/OutgoingAsync.h>";
     }
+    else if(p->hasNonLocalClassDecls())
+    {
+        H << "\n#include <Ice/Proxy.h>";
+    }
 
     if(p->hasNonLocalDataOnlyClasses() || p->hasNonLocalExceptions())
     {
