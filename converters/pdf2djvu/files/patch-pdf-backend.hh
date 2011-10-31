--- pdf-backend.hh.orig	2011-10-23 16:16:08.000000000 +0000
+++ pdf-backend.hh	2011-10-23 16:17:13.000000000 +0000
@@ -77,7 +77,11 @@
 
   namespace link
   {
+#if POPPLER_VERSION < 1700
     typedef ::Link Link;
+#else
+    typedef ::AnnotLink Link;
+#endif
     typedef ::LinkAction Action;
     typedef ::LinkDest Destination;
     typedef ::LinkGoTo GoTo;
