$FreeBSD$

--- ../../deploy/src/plugin/oji-plugin/include/mozilla_headers_ns600/nscore.h.orig	Fri Jul 30 18:00:04 2004
+++ ../../deploy/src/plugin/oji-plugin/include/mozilla_headers_ns600/nscore.h	Fri Jul 30 23:32:31 2004
@@ -163,7 +163,7 @@
   */
 
   /* under Metrowerks (Mac), we don't have autoconf yet */
-#ifdef __MWERKS__
+#if defined(__MWERKS__) || defined(NS_UNIX)
   #define HAVE_CPP_SPECIALIZATION
   #define HAVE_CPP_PARTIAL_SPECIALIZATION
   #define HAVE_CPP_MODERN_SPECIALIZE_TEMPLATE_SYNTAX
