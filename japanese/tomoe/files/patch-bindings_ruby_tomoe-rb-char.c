--- bindings/ruby/tomoe-rb-char.c.orig	2011-07-24 02:20:26.000000000 +0000
+++ bindings/ruby/tomoe-rb-char.c	2011-07-24 02:22:22.000000000 +0000
@@ -13,7 +13,7 @@
     if (NIL_P(xml)) {
         chr = tomoe_char_new();
     } else {
-        chr = tomoe_char_new_from_xml_data(RVAL2CSTR(xml), RSTRING(xml)->len);
+        chr = tomoe_char_new_from_xml_data(RVAL2CSTR(xml), RSTRING_LEN(xml));
     }
 
     G_INITIALIZE(self, chr);
