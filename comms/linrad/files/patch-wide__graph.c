--- wide_graph.c.orig	2023-02-21 22:04:43 UTC
+++ wide_graph.c
@@ -1591,7 +1591,7 @@ wg.ybottom=(int)(0.35F*(float)screen_height);
 }
 
 
-void init_wide_graph()
+void init_wide_graph(void)
 {
 if (read_modepar_file(GRAPHTYPE_WG) == 0)
   {
