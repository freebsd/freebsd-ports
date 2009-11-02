--- src/common.c.orig	2009-10-17 15:53:40.000000000 +0200
+++ src/common.c	2009-10-17 15:56:10.000000000 +0200
@@ -216,6 +216,9 @@ int             main(int argc, char *arg
 #if defined (HAVE_GTK) || defined (HAVE_GTK1)
 /* GTK+ stuff */
 	if (interactive == IN_GTK) {
+#if defined (HAVE_GTK) && defined (HAVE_NLS)
+		bind_textdomain_codeset((char *) PACKAGE, "UTF-8");
+#endif				/* HAVE_GTK && HAVE_NLS */
 #ifndef DUMMY_MIXER
 		if ((mixer_fd = open(device_filename, O_RDWR)) < 0)
 			return EOPENMIX;
