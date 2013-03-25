--- plugins/bmp/xp/ie_impGraphic_BMP.cpp.orig	2013-03-25 06:58:03.000000000 +0000
+++ plugins/bmp/xp/ie_impGraphic_BMP.cpp	2013-03-25 07:00:22.000000000 +0000
@@ -191,7 +191,7 @@
 
 	/* Clean Up Memory Used */
 		
-	FREEP(m_pPNGInfo->palette);
+	//FREEP(m_pPNGInfo->palette);
 	DELETEP(pBB);
 	png_destroy_write_struct(&m_pPNG, &m_pPNGInfo);
    
@@ -313,7 +313,7 @@
 	 * the normal method of doing things with libpng).  REQUIRED unless you
 	 * set up your own error handlers in the png_create_read_struct() earlier.
 	 */
-	if (setjmp(m_pPNG->jmpbuf))
+	if (setjmp(png_jmpbuf(m_pPNG)))
 	{
 		/* Free all of the memory associated with the png_ptr and info_ptr */
 		png_destroy_write_struct(&m_pPNG, &m_pPNGInfo);
@@ -332,7 +332,7 @@
 	UT_Error IE_ImpGraphic_BMP::Convert_BMP_Pallet(UT_ByteBuf* pBB)
 	{
 		/* Reset error handling for libpng */
-		if (setjmp(m_pPNG->jmpbuf))
+		if (setjmp(png_jmpbuf(m_pPNG)))
 		{
 			png_destroy_write_struct(&m_pPNG, &m_pPNGInfo);
 			return UT_ERROR;
@@ -372,7 +372,7 @@
 UT_Error IE_ImpGraphic_BMP::Convert_BMP(UT_ByteBuf* pBB)
 {
 	/* Reset error handling for libpng */
-	if (setjmp(m_pPNG->jmpbuf))
+	if (setjmp(png_jmpbuf(m_pPNG)))
 	{
 		png_destroy_write_struct(&m_pPNG, &m_pPNGInfo);
 		return UT_ERROR;
