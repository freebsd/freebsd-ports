--- ./src/Gui/NetworkRetriever.cpp.orig	Sat Feb 24 11:41:26 2007
+++ ./src/Gui/NetworkRetriever.cpp	Sun Apr 22 00:18:44 2007
@@ -361,7 +361,7 @@
   // start URL
   (*wget)<< startUrl;
 
-#ifdef FC_OS_LINUX
+#if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD)
   // on Linux it seems that we have to change cwd
   QString cwd = QDir::currentDirPath ();
   if ( !d->dir.isEmpty() )
