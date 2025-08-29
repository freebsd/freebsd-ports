--- include/VBox/sup.h.orig	2025-08-13 19:37:16 UTC
+++ include/VBox/sup.h
@@ -2325,7 +2325,7 @@ SUPR0DECL(void) SUPR0BadContext(PSUPDRVSESSION pSessio
 
 SUPR0DECL(void) SUPR0BadContext(PSUPDRVSESSION pSession, const char *pszFile, uint32_t uLine, const char *pszExpr);
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS)
 /**
  * Translates a physical address to a virtual mapping (valid up to end of page).
  * @returns VBox status code.
