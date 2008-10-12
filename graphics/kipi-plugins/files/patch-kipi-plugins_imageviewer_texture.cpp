--- kipi-plugins/imageviewer/texture.cpp.orig	2008-10-12 10:08:40.000000000 +0200
+++ kipi-plugins/imageviewer/texture.cpp	2008-10-12 10:09:00.000000000 +0200
@@ -28,7 +28,6 @@
 #include <kdebug.h>
 
 // LibKDcraw includes
-#include <libkdcraw/dcrawbinary.h>
 #include <libkdcraw/kdcraw.h>
 
 // Local includes
@@ -89,7 +88,7 @@
 	_texnr=tn;
 
 	// check if its a RAW file.
-	QString rawFilesExt(KDcrawIface::DcrawBinary::instance()->rawFiles());
+	QString rawFilesExt(KDcrawIface::KDcraw::rawFiles());
 	QFileInfo fileInfo(fn);
 	if (rawFilesExt.upper().contains( fileInfo.extension(false).upper() )) {
 		// it's a RAW file, use the libkdcraw loader
