--- ../psprint/source/printergfx/printerjob.cxx.orig	Sat Oct 19 14:49:13 2002
+++ ../psprint/source/printergfx/printerjob.cxx	Sat Oct 19 14:49:18 2002
@@ -285,8 +285,12 @@
 
     sal_Bool bSuccess = sal_False;
 
+#ifdef FREEBSD
+        pPWEntry = getpwuid( getuid());
+#else
     if (getpwuid_r(getuid(), &aPWEntry, pPWBuffer, sizeof(pPWBuffer), &pPWEntry) != 0)
         pPWEntry = NULL;
+#endif
 
     if (pPWEntry != NULL && pPWEntry->pw_name != NULL)
     {
