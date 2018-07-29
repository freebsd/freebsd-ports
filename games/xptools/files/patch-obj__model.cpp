--- src/AC3DPlugins/obj_model.cpp.orig	2018-07-05 08:41:42 UTC
+++ src/AC3DPlugins/obj_model.cpp
@@ -354,24 +354,28 @@ float		OBJ_get_anim_nth_angle(ACObject *
 int			OBJ_get_panel_left(ACObject * obj, int r)
 {
 	char tag[25];
-	sprintf(tag,"left0",r);
+	sprintf(tag,"%s","left0");
+	printf("%d",r);
 	return OBJ_get_property_int(obj,tag);
 }
 int			OBJ_get_panel_bottom(ACObject * obj, int r)
 {
 	char tag[25];
-	sprintf(tag,"bottom0",r);
+	sprintf(tag, "%s","bottom0");
+	printf("%d",r);
 	return OBJ_get_property_int(obj,tag);
 }
 int			OBJ_get_panel_right(ACObject * obj, int r)
 {
 	char tag[25];
-	sprintf(tag,"right0",r);
+	sprintf(tag,"%s","right0");
+	printf("%d",r);
 	return OBJ_get_property_int(obj,tag);
 }
 int			OBJ_get_panel_top(ACObject * obj, int r)
 {
 	char tag[25];
-	sprintf(tag,"top0",r);
+	sprintf(tag,"%s","top0");
+	printf("%d",r);
 	return OBJ_get_property_int(obj,tag);
-}
\ No newline at end of file
+}
