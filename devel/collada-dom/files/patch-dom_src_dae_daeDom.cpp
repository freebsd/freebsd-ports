--- dom/src/dae/daeDom.cpp.orig	2019-05-09 19:35:00 UTC
+++ dom/src/dae/daeDom.cpp
@@ -111,7 +111,7 @@ daeInt getDomAnyID(DAE& dae)
         return ColladaDOM141::domAny::ID();
     }
 #endif
-    return NULL;
+    return 0;
 }
 
 daeInt getDomSourceID(DAE& dae)
@@ -126,7 +126,7 @@ daeInt getDomSourceID(DAE& dae)
         return ColladaDOM141::domSource::ID();
     }
 #endif
-    return NULL;
+    return 0;
 }
 
 daeInt getDomCOLLADAID(const char* specversion)
@@ -141,7 +141,7 @@ daeInt getDomCOLLADAID(const char* specversion)
         return ColladaDOM141::domCOLLADA::ID();
     }
 #endif
-    return NULL;
+    return 0;
 }
 
 void copyElementAny(daeElementRef dstAny, daeElement* srcAny)
