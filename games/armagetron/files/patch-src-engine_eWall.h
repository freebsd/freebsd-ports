--- src/engine/eWall.h.orig	2007-10-02 18:12:07.000000000 +0200
+++ src/engine/eWall.h	2007-10-02 18:13:02.000000000 +0200
@@ -53,6 +53,8 @@
 
 
 class eWall;
+class eWallView;
+class eWallHolder;
 class eGameObject;
 
 class eWallView:public tHeapElement{
