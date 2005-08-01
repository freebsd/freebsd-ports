--- vec.h.orig	Thu Jun 30 02:06:00 2005
+++ vec.h	Tue Jul  5 12:33:19 2005
@@ -69,7 +69,7 @@
 
   // If your compiler complains the "The class "qglviewer::Vec" has no member "x"."
   // Add your architecture Q_OS_XXXX flag (see qglobal.h) in this list.
-#if defined (Q_OS_IRIX) || defined (Q_OS_AIX) || defined (Q_OS_HPUX)
+#if defined (Q_OS_IRIX) || defined (Q_OS_AIX) || defined (Q_OS_HPUX) || defined(Q_OS_FREEBSD)
 # define UNION_NOT_SUPPORTED
 #endif
 
