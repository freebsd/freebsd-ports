--- interface_gtk/interface_widget_envelope.cpp.orig	Sun Jan 20 23:56:00 2002
+++ interface_gtk/interface_widget_envelope.cpp	Fri Dec 27 21:58:41 2002
@@ -373,7 +373,7 @@
 		node_x=get_point_x(i);
 		node_y=get_point_y(i);
 
-		dist=(int)sqrt((p_node_x-node_x)*(p_node_x-node_x)+(p_node_y-node_y)*(p_node_y-node_y));
+		dist=(int)sqrt((double)((p_node_x-node_x)*(p_node_x-node_x)+(p_node_y-node_y)*(p_node_y-node_y)));
 
                 if (dist<6) {
 
