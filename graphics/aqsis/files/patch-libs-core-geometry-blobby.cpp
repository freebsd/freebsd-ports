--- libs/core/geometry/blobby.cpp.orig	2012-02-20 18:32:53.000000000 +0300
+++ libs/core/geometry/blobby.cpp	2012-02-20 18:33:07.000000000 +0300
@@ -392,7 +392,7 @@
 							try
 							{
 								CqString fullName = QGetRenderContext()->poptCurrent()
-									->findRiFile(dboName, "procedural").file_string();
+									->findRiFile(dboName, "procedural").string();
 								DBO_handle = DBO.SimpleDLOpen(&fullName);
 							}
 							catch(XqInvalidFile& /*e*/)
