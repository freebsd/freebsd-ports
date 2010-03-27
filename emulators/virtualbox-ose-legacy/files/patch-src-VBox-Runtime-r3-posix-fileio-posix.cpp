Index: src/VBox/Runtime/r3/posix/fileio-posix.cpp
===================================================================
--- src/VBox/Runtime/r3/posix/fileio-posix.cpp	(Revision 25952)
+++ src/VBox/Runtime/r3/posix/fileio-posix.cpp	(Revision 25953)
@@ -586,9 +586,9 @@
 }
 
 
-RTR3DECL(int) RTFileIoCtl(RTFILE File, int iRequest, void *pvData, unsigned cbData, int *piRet)
+RTR3DECL(int) RTFileIoCtl(RTFILE File, unsigned long ulRequest, void *pvData, unsigned cbData, int *piRet)
 {
-    int rc = ioctl((int)File, iRequest, pvData);
+    int rc = ioctl((int)File, ulRequest, pvData);
     if (piRet)
         *piRet = rc;
     return rc >= 0 ? VINF_SUCCESS : RTErrConvertFromErrno(errno);
