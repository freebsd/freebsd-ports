--- bdbxml2/bdbxml.h.orig	2011-04-06 19:35:39.000000000 +0000
+++ bdbxml2/bdbxml.h	2015-01-22 17:03:07.000000000 +0000
@@ -377,7 +377,7 @@
 static inline void
 rset_obj(VALUE obj)
 {
-    RBASIC(obj)->klass = rb_cData;
+    RBASIC_SET_CLASS_RAW(obj, rb_cData);
     RDATA(obj)->dfree = (RDF)free;
     RDATA(obj)->dmark = 0;
 }
