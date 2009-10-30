--- ./src/ImgArchiveSink.cpp.orig	2009-09-16 17:06:54.000000000 -0300
+++ ./src/ImgArchiveSink.cpp	2009-09-17 21:07:22.000000000 -0300
@@ -485,6 +485,7 @@
 	inf.type = SEVENZIP_ARCHIVE;
 	inf.name = "7z";
 	inf.extensions.append(".7z");
+	inf.extensions.append(".cb7");
         inf.reading = inf.writing = false;
 	if (which("7z") != QString::null)
 	{
