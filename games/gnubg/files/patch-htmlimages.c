Index: htmlimages.c
===================================================================
RCS file: /cvsroot/gnubg/gnubg/htmlimages.c,v
retrieving revision 1.20
retrieving revision 1.21
diff -u -r1.20 -r1.21
--- htmlimages.c	6 Jan 2004 12:30:36 -0000	1.20
+++ htmlimages.c	26 Jan 2004 07:36:02 -0000	1.21
@@ -777,7 +777,7 @@
 		free(asRefract[i]);
 }
 
-extern void CommandExportHTMLImages(char *sz)
+extern void CommandExportHTMLImages( char *sz )
 {
 	szFile = GetFilenameBase(sz);
 	if (!szFile)
@@ -791,10 +791,10 @@
 	TidyObjects();
 }
 
-#else
-extern void CommandExportHTMLImages( char * )
+#else /* not HAVE_LIBPNG */
+extern void CommandExportHTMLImages( char *sz )
 {
 	outputl( _("This installation of GNU Backgammon was compiled without\n"
 		"support for writing HTML images.") );
 }
-#endif
+#endif /* not HAVE_LIBPNG */
