--- libgphoto2_port/libgphoto2_port/gphoto2-port-info-list.c.orig	Sat Jun  3 17:38:12 2006
+++ libgphoto2_port/libgphoto2_port/gphoto2-port-info-list.c	Wed Jun 21 00:08:02 2006
@@ -51,6 +51,7 @@
 #  define dgettext(Domain,Message) (Message)
 #  define dcgettext(Domain,Message,Type) (Message)
 #  define bindtextdomain(Domain,Directory) (Domain)
+#  define bind_textdomain_codeset(Domain,codeset) (codeset)
 #  define _(String) (String)
 #  define N_(String) (String)
 #endif
