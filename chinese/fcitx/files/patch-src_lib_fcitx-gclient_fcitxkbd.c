--- src/lib/fcitx-gclient/fcitxkbd.c~	2012-07-17 15:21:04.000000000 -0500
+++ src/lib/fcitx-gclient/fcitxkbd.c	2012-07-18 00:25:05.368996486 -0500
@@ -45,11 +45,11 @@ static const gchar introspection_xml[] =
 "</node>";
 
 
-G_DEFINE_TYPE(FcitxKbd, fcitx_kbd, G_TYPE_DBUS_PROXY);
-
 FCITX_EXPORT_API
 GType        fcitx_kbd_get_type(void) G_GNUC_CONST;
 
+G_DEFINE_TYPE(FcitxKbd, fcitx_kbd, G_TYPE_DBUS_PROXY);
+
 static GDBusInterfaceInfo * _fcitx_kbd_get_interface_info(void);
 
 static GDBusInterfaceInfo *
