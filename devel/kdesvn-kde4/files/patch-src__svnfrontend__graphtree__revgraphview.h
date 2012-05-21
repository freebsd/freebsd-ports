--- src/svnfrontend/graphtree/revgraphview.h~	2012-05-21 15:28:34.000000000 -0300
+++ src/svnfrontend/graphtree/revgraphview.h	2012-05-21 15:28:40.000000000 -0300
@@ -49,7 +49,7 @@
 /**
 	@author Rajko Albrecht <ral@alwins-world.de>
 */
-class RevGraphView : virtual public QGraphicsView
+class RevGraphView : public QGraphicsView
 {
     Q_OBJECT
 public:
