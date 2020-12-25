--- app/actions/debug-actions.c.orig	2019-10-26 18:49:18 UTC
+++ app/actions/debug-actions.c
@@ -98,4 +98,10 @@ void
 debug_actions_update (GimpActionGroup *group,
                       gpointer         data)
 {
+#define SET_SENSITIVE(action,condition) \
+        gimp_action_group_set_action_sensitive (group, action, (condition) != 0)
+
+  SET_SENSITIVE ("debug-show-image-graph", gegl_has_operation ("gegl:introspect"));
+
+#undef SET_SENSITIVE
 }
