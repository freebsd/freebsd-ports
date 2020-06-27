--- commonui/ogdf/COGDFLayout.cpp.orig	2020-06-22 11:24:05 UTC
+++ commonui/ogdf/COGDFLayout.cpp
@@ -6,7 +6,7 @@
 
 #include <ogdf/basic/Graph.h>
 #include <ogdf/basic/GraphAttributes.h>
-#include <ogdf/module/LayoutModule.h>
+#include <ogdf/basic/LayoutModule.h>
 #include <ogdf/fileformats/GraphIO.h>
 
 #include <ogdf/misclayout/BalloonLayout.h>
@@ -246,16 +246,17 @@ bool COGDFLayout::loadGraph(const QString &filename, C
 {
     ogdf::Graph G;
     ogdf::GraphAttributes GA(G, 0xffffff);   // all attrs
+    std::ifstream is(filename.toStdString());
 
     QString format = QFileInfo(filename).suffix().toLower();
 
     bool ok = false;
     if (format == "gml")
-        ok = ogdf::GraphIO::readGML(GA, G, filename.toStdString());
+        ok = ogdf::GraphIO::readGML(GA, G, is);
 	else 
 		if (format == "dot" || format == "gv")
 		{
-			ok = ogdf::GraphIO::readDOT(GA, G, filename.toStdString());
+			ok = ogdf::GraphIO::readDOT(GA, G, is);
 			
 			// normalize node positions
 			if (ok && GA.has(GA.nodeGraphics))
