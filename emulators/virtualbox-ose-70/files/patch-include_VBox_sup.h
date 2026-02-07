--- include/VBox/sup.h.orig	2024-12-27 04:08:45.986426000 +0100
+++ include/VBox/sup.h	2024-12-27 04:09:08.925387000 +0100
@@ -2248,7 +2248,7 @@
 
 SUPR0DECL(void) SUPR0BadContext(PSUPDRVSESSION pSession, const char *pszFile, uint32_t uLine, const char *pszExpr);
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS)
 /**
  * Translates a physical address to a virtual mapping (valid up to end of page).
  * @returns VBox status code.
