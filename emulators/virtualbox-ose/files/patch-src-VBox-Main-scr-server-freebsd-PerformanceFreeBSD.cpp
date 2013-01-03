--- src/VBox/Main/src-server/freebsd/PerformanceFreeBSD.cpp.orig	2012-10-19 19:51:26.256773940 +0400
+++ src/VBox/Main/src-server/freebsd/PerformanceFreeBSD.cpp	2012-10-19 19:51:49.835771918 +0400
@@ -109,5 +109,10 @@
     return E_NOTIMPL;
 }
 
+int getDiskListByFs(const char *name, DiskList& list)
+{
+    return VERR_NOT_IMPLEMENTED;
+}
+
 } /* namespace pm */
 
