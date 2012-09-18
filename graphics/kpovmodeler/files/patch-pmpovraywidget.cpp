--- ./pmpovraywidget.cpp.orig	2009-08-31 15:13:57.000000000 +0000
+++ ./pmpovraywidget.cpp	2012-08-08 22:00:05.311318130 +0000
@@ -237,12 +237,6 @@
    QFile* file = 0;
    bool ok = true;
 
-   if( !s_imageFormatsRegistered )
-   {
-
-      s_imageFormatsRegistered = true;
-   }
-
    KUrl url = KFileDialog::getSaveUrl( KUrl( ), KImageIO::pattern( KImageIO::Writing ) );
    if( url.isEmpty( ) )
       return;
@@ -255,17 +249,7 @@
       return;
    }
 
-#ifdef __GNUC__
-#warning is this really needed?
-#endif
-   QString suffix = url.fileName().toUpper();
-   if (suffix.lastIndexOf('.') >= 0)
-     suffix = suffix.mid(suffix.lastIndexOf('.'));
-
-   QString format;
-
-   if (QImageWriter::supportedImageFormats().contains(suffix.toLatin1()))
-      format = suffix;
+   QString format = url.fileName().section('.', -1);
 
    if( format.isEmpty( ) )
    {
@@ -274,12 +258,6 @@
       return;
    }
 
-   if( !KImageIO::types( ).contains(format) )
-   {
-      KMessageBox::error( this, i18n( "Format is not supported for writing." ) );
-      return;
-   }
-
    if( url.isLocalFile( ) )
    {
       // Local file
