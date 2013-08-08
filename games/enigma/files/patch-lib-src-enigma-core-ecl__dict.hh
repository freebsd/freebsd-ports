--- lib-src/enigma-core/ecl_dict.hh.orig	2007-09-08 16:20:05.000000000 +0400
+++ lib-src/enigma-core/ecl_dict.hh	2013-07-10 23:08:37.858113264 +0400
@@ -27,6 +27,7 @@
     extern unsigned hash(const std::string &key);
 
     class XInvalidKey : XGeneric {
+    public:
 	XInvalidKey () : XGeneric("invalid dictionary key")
         {}
     };
