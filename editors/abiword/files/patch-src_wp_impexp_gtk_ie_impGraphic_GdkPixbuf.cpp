--- src/wp/impexp/gtk/ie_impGraphic_GdkPixbuf.cpp.orig	2010-04-14 23:50:13.000000000 +0200
+++ src/wp/impexp/gtk/ie_impGraphic_GdkPixbuf.cpp	2012-04-28 07:25:54.000000000 +0200
@@ -185,7 +185,7 @@
 /** needed for the stejmp context */
 UT_Error IE_ImpGraphic_GdkPixbuf::_png_write(GdkPixbuf * pixbuf)
 {
-	if (setjmp(m_pPNG->jmpbuf))
+	if (setjmp(png_jmpbuf(m_pPNG)))
 	{
 		DELETEP(m_pPngBB);
 		png_destroy_write_struct(&m_pPNG, &m_pPNGInfo);
@@ -446,7 +446,7 @@
 	 * the normal method of doing things with libpng).  REQUIRED unless you
 	 * set up your own error handlers in the png_create_read_struct() earlier.
 	 */
-	if (setjmp(m_pPNG->jmpbuf))
+	if (setjmp(png_jmpbuf(m_pPNG)))
 	{
 		/* Free all of the memory associated with the png_ptr and info_ptr */
 		png_destroy_write_struct(&m_pPNG, &m_pPNGInfo);
