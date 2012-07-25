--- src/lib/fcitx-gclient/fcitxinputmethod.c~	2012-07-17 15:21:04.000000000 -0500
+++ src/lib/fcitx-gclient/fcitxinputmethod.c	2012-07-18 00:24:39.533453747 -0500
@@ -58,11 +58,11 @@ enum {
 
 static guint signals[LAST_SIGNAL] = {0};
 
-G_DEFINE_TYPE(FcitxInputMethod, fcitx_input_method, G_TYPE_DBUS_PROXY);
-
 FCITX_EXPORT_API
 GType        fcitx_input_method_get_type(void) G_GNUC_CONST;
 
+G_DEFINE_TYPE(FcitxInputMethod, fcitx_input_method, G_TYPE_DBUS_PROXY);
+
 static GDBusInterfaceInfo * _fcitx_input_method_get_interface_info(void);
 static void _fcitx_im_item_foreach_cb(gpointer data, gpointer user_data);
 
