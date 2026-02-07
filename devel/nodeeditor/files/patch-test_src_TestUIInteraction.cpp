--- test/src/TestUIInteraction.cpp.orig	2025-10-09 16:54:05 UTC
+++ test/src/TestUIInteraction.cpp
@@ -20,6 +20,7 @@
 #include <QGraphicsScene>
 #include <QTimer>
 
+using namespace Catch;
 using QtNodes::BasicGraphicsScene;
 using QtNodes::ConnectionGraphicsObject;
 using QtNodes::ConnectionId;
