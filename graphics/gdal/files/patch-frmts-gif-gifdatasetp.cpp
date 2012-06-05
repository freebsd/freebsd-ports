Ref: http://trac.osgeo.org/gdal/ticket/4675

--- frmts/gif/gifdataset.cpp.orig	2012-05-17 11:30:54.000000000 +0800
+++ frmts/gif/gifdataset.cpp	2012-06-05 00:23:12.988213306 +0800
@@ -469,6 +469,28 @@
     return poDS;
 }
 
+ /************************************************************************/
+/*                        GDALPrintGifError()                           */
+/************************************************************************/
+
+static void GDALPrintGifError(const char* pszMsg)
+{
+/* GIFLIB_MAJOR is only defined in libgif >= 4.2.0 */
+/* libgif 4.2.0 has retired PrintGifError() and added GifErrorString() */
+#if defined(GIFLIB_MAJOR) && defined(GIFLIB_MINOR) && \
+        ((GIFLIB_MAJOR == 4 && GIFLIB_MINOR >= 2) || GIFLIB_MAJOR > 4)
+    /* Static string actually, hence the const char* cast */
+    const char* pszGIFLIBError = (const char*) GifErrorString();
+    if (pszGIFLIBError == NULL)
+        pszGIFLIBError = "Unknown error";
+    CPLError( CE_Failure, CPLE_AppDefined,
+              "%s. GIFLib Error : %s", pszMsg, pszGIFLIBError );
+#else
+    PrintGifError();
+    CPLError( CE_Failure, CPLE_AppDefined, "%s", pszMsg );
+#endif
+}
+
 /************************************************************************/
 /*                             CreateCopy()                             */
 /************************************************************************/
@@ -596,9 +618,7 @@
                           psGifCT->ColorCount, 255, psGifCT) == GIF_ERROR)
     {
         FreeMapObject(psGifCT);
-        PrintGifError();
-        CPLError( CE_Failure, CPLE_AppDefined, 
-                  "Error writing gif file." );
+        GDALPrintGifError("Error writing gif file.");
         EGifCloseFile(hGifFile);
         VSIFCloseL( fp );
         return NULL;
@@ -622,9 +642,7 @@
 
     if (EGifPutImageDesc(hGifFile, 0, 0, nXSize, nYSize, bInterlace, NULL) == GIF_ERROR )
     {
-        PrintGifError();
-        CPLError( CE_Failure, CPLE_AppDefined, 
-                  "Error writing gif file." );
+        GDALPrintGifError("Error writing gif file.");
         EGifCloseFile(hGifFile);
         VSIFCloseL( fp );
         return NULL;
