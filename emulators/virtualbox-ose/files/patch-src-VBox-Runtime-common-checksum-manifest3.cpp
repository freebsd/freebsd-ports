--- src/VBox/Runtime/common/checksum/manifest3.cpp.orig	2015-03-02 10:09:59.000000000 -0500
+++ src/VBox/Runtime/common/checksum/manifest3.cpp	2015-03-12 15:40:09.008443000 -0400
@@ -427,7 +427,7 @@
     uint32_t cRefs = RTManifestRetain(hManifest);
     AssertReturn(cRefs != UINT32_MAX, VERR_INVALID_HANDLE);
     cRefs = RTVfsIoStrmRetain(hVfsIos);
-    AssertReturnStmt(cRefs != UINT32_MAX, VERR_INVALID_HANDLE, RTManifestRelease(hManifest));
+    AssertReturnStmt(cRefs != UINT32_MAX, RTManifestRelease(hManifest), VERR_INVALID_HANDLE);
 
     /*
      * Create an instace of the passthru I/O stream.
