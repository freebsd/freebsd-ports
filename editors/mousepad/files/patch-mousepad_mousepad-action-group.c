--- mousepad/mousepad-action-group.c.orig	2014-09-01 20:50:07 UTC
+++ mousepad/mousepad-action-group.c
@@ -124,7 +124,7 @@ mousepad_action_group_class_init (MousepadActionGroupC
                 G_SIGNAL_RUN_LAST,
                 0, NULL, NULL,
                 g_cclosure_marshal_VOID__OBJECT,
-                G_TYPE_NONE, 0,
+                G_TYPE_NONE, 1,
                 GTK_SOURCE_TYPE_LANGUAGE);
 }
 
@@ -302,11 +302,6 @@ mousepad_action_group_set_active_style_scheme (Mousepa
   gtk_toggle_action_set_active (GTK_TOGGLE_ACTION (action), TRUE);
   self->locked = FALSE;
 
-  /* update the setting when the active action is changed */
-  self->locked = TRUE;
-  MOUSEPAD_SETTING_SET_STRING (COLOR_SCHEME, gtk_source_style_scheme_get_id (scheme));
-  self->locked = FALSE;
-
   g_object_notify (G_OBJECT (self), "active-style-scheme");
 }
 
@@ -473,6 +468,8 @@ static void
 mousepad_action_group_style_scheme_action_activate (MousepadActionGroup       *self,
                                                     MousepadStyleSchemeAction *action)
 {
+  const gchar *scheme_name = NULL;
+
   /* only update the active action if we're not already in the process of
    * setting it and the sender action is actually active */
   if (! self->locked &&
@@ -481,7 +478,14 @@ mousepad_action_group_style_scheme_action_activate (Mo
       GtkSourceStyleScheme *scheme;
 
       scheme = mousepad_style_scheme_action_get_style_scheme (action);
-      mousepad_action_group_set_active_style_scheme (self, scheme);
+
+      /* update the setting when the active action is changed */
+      if (scheme != NULL)
+        scheme_name = gtk_source_style_scheme_get_id(scheme);
+
+      self->locked = TRUE;
+      MOUSEPAD_SETTING_SET_STRING (COLOR_SCHEME, scheme_name);
+      self->locked = FALSE;
     }
 }
 
