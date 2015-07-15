--- mousepad/mousepad-action-group.c.orig	2014-09-01 20:50:07 UTC
+++ mousepad/mousepad-action-group.c
@@ -283,7 +283,8 @@ void
 mousepad_action_group_set_active_style_scheme (MousepadActionGroup  *self,
                                                GtkSourceStyleScheme *scheme)
 {
-  GtkAction *action;
+  GtkAction   *action;
+  const gchar *scheme_name = NULL;
 
   g_return_if_fail (MOUSEPAD_IS_ACTION_GROUP (self));
 
@@ -303,8 +304,11 @@ mousepad_action_group_set_active_style_s
   self->locked = FALSE;
 
   /* update the setting when the active action is changed */
+  if (scheme != NULL)
+    scheme_name = gtk_source_style_scheme_get_id(scheme);
+
   self->locked = TRUE;
-  MOUSEPAD_SETTING_SET_STRING (COLOR_SCHEME, gtk_source_style_scheme_get_id (scheme));
+  MOUSEPAD_SETTING_SET_STRING (COLOR_SCHEME, scheme_name);
   self->locked = FALSE;
 
   g_object_notify (G_OBJECT (self), "active-style-scheme");
