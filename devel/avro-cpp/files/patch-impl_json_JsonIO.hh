--- impl/json/JsonIO.hh.orig	2015-12-02 18:53:55 UTC
+++ impl/json/JsonIO.hh
@@ -159,7 +159,7 @@ class AVRO_DECL JsonGenerator {
 
     void escapeCtl(char c) {
         out_.write('\\');
-        out_.write('U');
+        out_.write('u'); // https://issues.apache.org/jira/browse/AVRO-1191
         out_.write('0');
         out_.write('0');
         out_.write(toHex((static_cast<unsigned char>(c)) / 16));
