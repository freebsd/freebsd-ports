--- src/xmlview.c.orig	Tue Jun 10 16:07:16 2003
+++ src/xmlview.c	Sat Aug 30 18:57:56 2003
@@ -877,7 +877,7 @@
 		enum CongNodeType node_type = cong_node_type(x);
 		const char *name = xml_frag_name_nice(x);

-		if (node_type == CONG_NODE_TYPE_ELEMENT && cong_dispspec_element_structural(ds, name))
+		if (node_type == CONG_NODE_TYPE_ELEMENT && cong_dispspec_element_structural(ds, cong_node_get_xmlns(x), name))
 		{
 			return(cong_node_prev(x));
 		}
