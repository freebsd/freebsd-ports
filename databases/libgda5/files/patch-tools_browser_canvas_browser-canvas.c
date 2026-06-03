--- tools/browser/canvas/browser-canvas.c.orig	2020-11-08 20:23:20 UTC
+++ tools/browser/canvas/browser-canvas.c
@@ -853,7 +853,7 @@ browser_canvas_perform_auto_layout (BrowserCanvas *can
 
 #ifdef GRAPHVIZ_NEW_API
 	graph = agopen ("BrowserCanvasLayout", Agdirected, NULL);
-        agnode (graph, "shape", "box");
+        agnode (graph, "shape", 1);
         agset (graph, "height", ".1");
         agset (graph, "width", ".1");
         agset (graph, "fixedsize", "true");
