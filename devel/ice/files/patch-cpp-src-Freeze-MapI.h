--- cpp.orig/src/Freeze/MapI.h	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/Freeze/MapI.h	2012-09-10 11:43:58.000000000 +0200
@@ -63,12 +63,13 @@ public:
     void
     close();
 
-    class Tx : public IceUtil::SimpleShared
+    class Tx : public IceUtil::SimpleSharedUnsafeDestructor
     {
     public:
 
         Tx(const MapHelperI&);
-        ~Tx();
+        ~Tx() ICE_NOEXCEPT_FALSE;
+        ;
 
         void dead();
 
