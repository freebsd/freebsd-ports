--- src/AC3DPlugins/obj_editor.cpp.orig	2018-07-05 08:52:21 UTC
+++ src/AC3DPlugins/obj_editor.cpp
@@ -445,9 +445,9 @@ void	OBJ_editor_init(void)
 	for (uintptr_t n = 0; n < NUM_KEYFRAMES; ++n)
 	{
 		char	buf[25];
-		sprintf(buf,"xplane_anim_value%d", n);
+		sprintf(buf,"xplane_anim_value%lu", n);
 		anim_value_vars[n] = new TCL_linked_vardv(ac_get_tcl_interp(), STRING(buf), MAX_MULTI_COUNT, xplane_anim_value_cb, (void *) n, 0);
-		sprintf(buf,"xplane_anim_angle%d", n);
+		sprintf(buf,"xplane_anim_angle%lu", n);
 		anim_angle_vars[n] = new TCL_linked_vardv(ac_get_tcl_interp(), STRING(buf), MAX_MULTI_COUNT, xplane_anim_angle_cb, (void *) n, 0);
 	}
 
