--- print-callbacks.c.ori	Fri Jan 31 18:49:46 2003
+++ print-callbacks.c	Fri Jan 31 18:51:39 2003
@@ -25,11 +25,8 @@
 
 #include <libgnome/libgnome.h>
 #include <libgnomeprint/gnome-print.h>
-#include <libgnomeprint/gnome-print-master.h>
 #include <libgnomeprintui/gnome-print-preview.h>
-#include <libgnomeprintui/gnome-print-master-preview.h>
 #include <libgnomeprintui/gnome-print-dialog.h>
-#include <libgnomeprintui/gnome-printer-dialog.h>
 #include <libgnomeprintui/gnome-print-paper-selector.h>
 #include <libgnomecanvas/libgnomecanvas.h>
 #include <libgnomevfs/gnome-vfs-utils.h>
@@ -68,7 +65,6 @@
 	double               paper_bmargin;
 
 	GnomePrintConfig    *config;
-	GnomePrintMaster    *gpm;
 
 	gboolean             print_comment;
 	gboolean             portrait;
@@ -117,8 +113,6 @@
 	pi->ref_count--;
 
 	if (pi->ref_count == 0) {
-		if (pi->gpm != NULL)
-			g_object_unref (pi->gpm);
 		gnome_print_config_unref (pi->config);
 		g_object_unref (pi->pixbuf);
 		g_object_unref (pi->font_comment);
@@ -727,11 +721,7 @@
 
 	/* Print !! */
 
-	pi->gpm = gnome_print_master_new_from_config (pi->config);
-	gp_ctx = gnome_print_master_get_context (pi->gpm);
 	print_image (gp_ctx, pi, FALSE);
-	gnome_print_master_close (pi->gpm);
-	gnome_print_master_print (pi->gpm);	
 	print_info_unref (pi);
 }
 
@@ -938,7 +928,7 @@
 	notebook     = glade_xml_get_widget (data->gui, "notebook");
 
 	gtk_box_pack_start (GTK_BOX (printer_vbox),
-			    gnome_printer_selection_new (pi->config), 
+			    gtk_label_new("Sorry, printing is currently broken"), 
 			    FALSE, FALSE, 0);
 	gtk_box_pack_start (GTK_BOX (paper_vbox),
 			    gnome_paper_selector_new (pi->config), /*FIXME*/
