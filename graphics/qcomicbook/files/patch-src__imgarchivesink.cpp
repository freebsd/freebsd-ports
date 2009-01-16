--- ./src/imgarchivesink.cpp.orig	2009-01-06 01:05:14.000000000 -0200
+++ ./src/imgarchivesink.cpp	2009-01-06 01:06:26.000000000 -0200
@@ -471,6 +471,7 @@
 	inf.type = SEVENZIP_ARCHIVE;
 	inf.name = "7z";
 	inf.extensions.append(".7z");
+	inf.extensions.append(".cb7");
 	if (which("7z") != QString::null)
 	{
 		inf.extractopts.append("7z");
