--- src/xmms_about.c.orig	Wed Jul 23 04:53:36 2003
+++ src/xmms_about.c	Wed Jul 23 04:54:43 2003
@@ -20,11 +20,11 @@
     gtk_container_border_width(GTK_CONTAINER(hbox1), 5);
 
     label = gtk_label_new(
-	"
-TFMX plugin adapted to xmms by David Le Corfec
-<dlecorfec@users.sourceforge.net>
-Original code (tfmxplay) by Jonathan H. Pickard, ported to Winamp by Per Linden\n
-TFMX was created by Chris Huelsbeck.
+	"\
+TFMX plugin adapted to xmms by David Le Corfec\
+<dlecorfec@users.sourceforge.net>\n\
+Original code (tfmxplay) by Jonathan H. Pickard, ported to Winamp by Per Linden\n\
+TFMX was created by Chris Huelsbeck.\
 ");
     gtk_box_pack_start(GTK_BOX(dialog_vbox1), label,
 		       TRUE, TRUE, 5);
