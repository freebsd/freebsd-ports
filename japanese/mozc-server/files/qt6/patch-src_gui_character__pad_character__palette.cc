--- src/gui/character_pad/character_palette.cc.orig	2026-09-15 04:12:45 UTC
+++ src/gui/character_pad/character_palette.cc
@@ -177,9 +177,7 @@ CharacterPalette::CharacterPalette(QWidget *parent)
   showLocalTable(kCP932Map, kCP932MapSize);
   categoryTreeWidget->setCurrentItem(sjis_item);
 
-  categoryTreeWidget->setItemExpanded(
-      categoryTreeWidget->topLevelItem(0)->parent(),
-      true);
+  categoryTreeWidget->topLevelItem(0)->parent()->setExpanded(true);
 
   // Select "Shift-JIS" item as a default.
   categoryTreeWidget->setCurrentItem(sjis_item);
@@ -245,7 +243,7 @@ void CharacterPalette::updateTableSize() {
   // here we use "龍" to calc font size, as it looks almsot square
   const char kHexBaseChar[]= "龍";
   const QRect rect =
-      QFontMetrics(tableWidget->font()).boundingRect(trUtf8(kHexBaseChar));
+      QFontMetrics(tableWidget->font()).boundingRect(tr(kHexBaseChar));
 
 #ifdef OS_MACOSX
   const int width = static_cast<int>(rect.width() * 2.2);
@@ -319,7 +317,7 @@ void CharacterPalette::showUnicodeTableByRange(const U
   QStringList row_header;
   for (char32 ucs4 = range.first; ucs4 <= range.last; ucs4 += kHexBase) {
     QString str;
-    str.sprintf("U+%3.3X0", ucs4 / kHexBase);
+    str.asprintf("U+%3.3X0", ucs4 / kHexBase);
     row_header << str;
   }
 
@@ -401,7 +399,7 @@ void CharacterPalette::showLocalTable(const LocalChara
   QStringList row_header;
   for (int i = from_start; i < from_end; i += kHexBase) {
     QString str;
-    str.sprintf("0x%X0", i / kHexBase);
+    str.asprintf("0x%X0", i / kHexBase);
     row_header << str;
   }
 
