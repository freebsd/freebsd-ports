--- ../stoc/source/javavm/interact.cxx.orig	Fri Mar 21 11:58:45 2003
+++ ../stoc/source/javavm/interact.cxx	Fri Mar 21 12:01:18 2003
@@ -129,7 +129,7 @@
     m_aRequest(rRequest)
 {
     bool bRetry;
-#if defined LINUX
+#if defined LINUX || defined FREEBSD
     // Only if Java is disabled we allow retry:
     bRetry = m_aRequest.isExtractableTo(
         getCppuType(static_cast< css::java::JavaDisabledException * >(0)));
