--- src/gui/character_pad/unicode_util.cc.orig	2026-09-15 04:03:16 UTC
+++ src/gui/character_pad/unicode_util.cc
@@ -148,7 +148,7 @@ QString toCodeInUcs4(const QString &str) {
     return "";
   }
   QString result;
-  result.sprintf("U+%04X", ucs4);
+  result.asprintf("U+%04X", ucs4);
   return result;
 }
 
@@ -160,7 +160,7 @@ QString toHexUTF8(const QString &str) {
   QString result;
   for (int i = 0; i < array.size(); ++i) {
     QString tmp;
-    tmp.sprintf("%02X ", static_cast<uint8>(array[i]));
+    tmp.asprintf("%02X ", static_cast<uint8>(array[i]));
     result += tmp;
   }
   return result;
@@ -174,9 +174,9 @@ QString Hexify(uint16 code) {
   const uint16 high = (code >> 8) & 0xFF;
   const uint16 low = code & 0xFF;
   if (high == 0) {
-    tmp.sprintf("%02X", low);
+    tmp.asprintf("%02X", low);
   } else {
-    tmp.sprintf("%02X %02X", high, low);
+    tmp.asprintf("%02X %02X", high, low);
   }
   return tmp;
 }
@@ -245,7 +245,7 @@ QString UnicodeUtil::GetToolTip(const QFont &font, con
     // }
     // if (unihan->total_strokes > 0) {
     //   QString tmp;
-    //   tmp.sprintf("%d", unihan->total_strokes);
+    //   tmp.asprintf("%d", unihan->total_strokes);
     //   info += "<tr><td>" + QObject::tr("Total Strokes") + ":</td><td>";
     //   info += toHtmlEscaped(tmp);
     //   info += "</td></tr>";
