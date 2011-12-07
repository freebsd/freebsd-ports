--- plugins/midi_import/portsmf/allegrowr.cpp.orig	2011-10-03 12:30:46.000000000 +0000
+++ plugins/midi_import/portsmf/allegrowr.cpp	2011-10-03 12:30:46.000000000 +0000
@@ -41,7 +41,7 @@
         break;
     case 's': {
         string str;
-        string_escape(str, p->s, "\"");
+        string_escape(str, p->s, (char *)"\"");
         file << str;
         break;
     }
