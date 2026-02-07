--- src/VBox/Runtime/r0drv/freebsd/assert-r0drv-freebsd.c.orig	2021-01-07 15:42:08 UTC
+++ src/VBox/Runtime/r0drv/freebsd/assert-r0drv-freebsd.c
@@ -68,15 +68,18 @@
 
 DECLHIDDEN(void) rtR0AssertNativeMsg1(const char *pszExpr, unsigned uLine, const char *pszFile, const char *pszFunction)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     printf("\r\n!!Assertion Failed!!\r\n"
            "Expression: %s\r\n"
            "Location  : %s(%d) %s\r\n",
            pszExpr, pszFile, uLine, pszFunction);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
 }
 
 
 DECLHIDDEN(void) rtR0AssertNativeMsg2V(bool fInitial, const char *pszFormat, va_list va)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     char szMsg[256];
 
     RTStrPrintfV(szMsg, sizeof(szMsg) - 1, pszFormat, va);
@@ -84,6 +87,7 @@ DECLHIDDEN(void) rtR0AssertNativeMsg2V(bool fInitial, 
     printf("%s", szMsg);
 
     NOREF(fInitial);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
 }
 
 
