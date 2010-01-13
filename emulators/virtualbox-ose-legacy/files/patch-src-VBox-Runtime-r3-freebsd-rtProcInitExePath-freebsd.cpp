--- src/VBox/Runtime/r3/freebsd/rtProcInitExePath-freebsd.cpp	(revision 25471)
+++ src/VBox/Runtime/r3/freebsd/rtProcInitExePath-freebsd.cpp	(revision 25472)
@@ -32,6 +32,8 @@
 *   Header Files                                                               *
 *******************************************************************************/
 #define LOG_GROUP RTLOGGROUP_PROCESS
+#include <sys/param.h>
+#include <sys/sysctl.h>
 #include <unistd.h>
 #include <errno.h>
 #include <dlfcn.h>
@@ -47,17 +49,20 @@
 
 DECLHIDDEN(int) rtProcInitExePath(char *pszPath, size_t cchPath)
 {
-    /*
-     * Read the /proc/curproc/file link, convert to native and return it.
-     */
-    int cchLink = readlink("/proc/curproc/file", pszPath, cchPath - 1);
-    if (cchLink > 0 && (size_t)cchLink <= cchPath - 1)
-    {
-        pszPath[cchLink] = '\0';
+    int aiName[4];
+    size_t cchExePath;
 
+    aiName[0] = CTL_KERN;
+    aiName[1] = KERN_PROC;
+    aiName[2] = KERN_PROC_PATHNAME;
+    aiName[3] = getpid();
+
+    cchExePath = cchPath - 1;
+    if(sysctl(aiName, RT_ELEMENTS(aiName), pszPath, &cchExePath, NULL, 0) == 0)
+    {
         char *pszTmp = NULL;
         int rc = rtPathFromNative(&pszTmp, pszPath);
-        AssertMsgRCReturn(rc, ("rc=%Rrc pszLink=\"%s\"\nhex: %.*Rhsx\n", rc, pszPath, cchLink, pszPath), rc);
+        AssertMsgRCReturn(rc, ("rc=%Rrc pszLink=\"%s\"\nhex: %.*Rhsx\n", rc, pszPath, cchExePath, pszPath), rc);
 
         size_t cch = strlen(pszTmp);
         AssertReturn(cch <= cchPath, VERR_BUFFER_OVERFLOW);
@@ -68,39 +73,8 @@
         return VINF_SUCCESS;
     }
 
-    int err = errno;
-
-    /*
-     * Fall back on the dynamic linker since /proc is optional.
-     */
-    void *hExe = dlopen(NULL, 0);
-    if (hExe)
-    {
-        struct link_map const *pLinkMap = 0;
-        if (dlinfo(hExe, RTLD_DI_LINKMAP, &pLinkMap) == 0)
-        {
-            const char *pszImageName = pLinkMap->l_name;
-            if (*pszImageName == '/') /* this may not always be absolute, despite the docs. :-( */
-            {
-                char *pszTmp = NULL;
-                int rc = rtPathFromNative(&pszTmp, pszImageName);
-                AssertMsgRCReturn(rc, ("rc=%Rrc pszImageName=\"%s\"\n", rc, pszImageName), rc);
-
-                size_t cch = strlen(pszTmp);
-                AssertReturn(cch <= cchPath, VERR_BUFFER_OVERFLOW);
-
-                memcpy(pszPath, pszTmp, cch + 1);
-                RTStrFree(pszTmp);
-
-                return VINF_SUCCESS;
-            }
-            /** @todo Try search the PATH for the file name or append the current
-             *        directory, which ever makes sense... */
-        }
-    }
-
-    int rc = RTErrConvertFromErrno(err);
-    AssertMsgFailed(("rc=%Rrc err=%d cchLink=%d hExe=%p\n", rc, err, cchLink, hExe));
+    int rc = RTErrConvertFromErrno(errno);
+    AssertMsgFailed(("rc=%Rrc errno=%d cchLink=%d\n", rc, errno, cchExePath));
     return rc;
 }
