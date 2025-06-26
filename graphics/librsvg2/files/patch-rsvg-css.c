--- rsvg-css.c.orig	2018-10-01 22:50:22 UTC
+++ rsvg-css.c
@@ -839,7 +839,11 @@ static void
 }
 
 static void
+#if LIBXML_VERSION < 21200
 rsvg_xml_noerror (void *data, xmlErrorPtr error)
+#else
+rsvg_xml_noerror (void *data, const xmlError *error)
+#endif
 {
 }
 
