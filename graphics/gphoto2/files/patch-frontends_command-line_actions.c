--- frontends/command-line/actions.c.orig	Sat Aug 31 20:34:21 2002
+++ frontends/command-line/actions.c	Sat Aug 31 20:36:35 2002
@@ -316,6 +316,7 @@
         const char *data;
         unsigned long size;
         ExifData *ed;
+	unsigned int i;
 
         CR (gp_file_new (&file));
         CRU (gp_camera_file_get (p->camera, p->folder, filename,
@@ -337,16 +338,9 @@
         printf ("%-59.59s", _("Value"));
         printf ("\n");
         print_hline ();
-        if (ed->ifd0)
-                show_ifd (ed->ifd0);
-        if (ed->ifd1)
-                show_ifd (ed->ifd1);
-        if (ed->ifd_exif)
-                show_ifd (ed->ifd_exif);
-        if (ed->ifd_gps)
-                show_ifd (ed->ifd_gps);
-        if (ed->ifd_interoperability)
-                show_ifd (ed->ifd_interoperability);
+	for (i = 0; i < EXIF_IFD_COUNT; i++)
+	    	if (ed->ifd[i])
+		    	show_ifd (ed->ifd[i]);
         print_hline ();
         if (ed->size) {
                 printf (_("EXIF data contains a thumbnail (%i bytes)."),
