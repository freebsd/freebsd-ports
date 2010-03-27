Index: include/iprt/file.h
===================================================================
--- include/iprt/file.h	(Revision 25952)
+++ include/iprt/file.h	(Revision 25953)
@@ -743,7 +743,7 @@
  * @param   cbData      Size of the IOCTL data.
  * @param   piRet       Return value of the IOCTL request.
  */
-RTR3DECL(int) RTFileIoCtl(RTFILE File, int iRequest, void *pvData, unsigned cbData, int *piRet);
+RTR3DECL(int) RTFileIoCtl(RTFILE File, unsigned long ulRequest, void *pvData, unsigned cbData, int *piRet);
 
 /**
  * Query the sizes of a filesystem.
