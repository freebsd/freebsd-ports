--- ../psprint/source/printergfx/printerjob.cxx.orig	Sat Mar  2 22:22:50 2002
+++ ../psprint/source/printergfx/printerjob.cxx	Sat Mar  2 22:22:40 2002
@@ -282,7 +282,11 @@
 
     sal_Bool bSuccess = sal_False;
 
+#ifdef FREEBSD
+    if (pPWEntry = getpwuid(getuid()) != NULL)
+#else
     if (getpwuid_r(getuid(), &aPWEntry, pPWBuffer, sizeof(pPWBuffer), &pPWEntry) != 0)
+#endif
         pPWEntry = NULL;
 
     if (pPWEntry != NULL && pPWEntry->pw_name != NULL)
