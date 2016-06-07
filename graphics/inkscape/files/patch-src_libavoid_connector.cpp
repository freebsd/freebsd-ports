--- src/libavoid/connector.cpp.orig	2014-11-30 18:45:32 UTC
+++ src/libavoid/connector.cpp
@@ -885,7 +885,7 @@ bool ConnRef::generatePath(void)
             {
                 // Check for consecutive points on opposite 
                 // corners of two touching shapes.
-                COLA_ASSERT(abs(i->pathNext->id.objID - i->id.objID) != 2);
+                COLA_ASSERT(abs((int)(i->pathNext->id.objID - i->id.objID)) != 2);
             }
         }
     }
