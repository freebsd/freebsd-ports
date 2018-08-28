--- src/canvas.cpp.orig	2018-08-28 10:55:27 UTC
+++ src/canvas.cpp
@@ -209,11 +209,11 @@ void Canvas::slotPrint(const QString& te
 void Canvas::slotFontType(const QString& family, const QString& extra)
 {
 	textFont->setFamily(family);
-	textFont->setBold(extra.contains(i18n("bold")) > 0);
-	textFont->setItalic(extra.contains(i18n("italic")) > 0);
-	textFont->setUnderline(extra.contains(i18n("underline")) > 0);
-	textFont->setOverline(extra.contains(i18n("overline")) > 0);
-	textFont->setStrikeOut(extra.contains(i18n("strikeout")) > 0);
+	textFont->setBold(bool(extra.contains(i18n("bold"))));
+	textFont->setItalic(bool(extra.contains(i18n("italic"))));
+	textFont->setUnderline(bool(extra.contains(i18n("underline"))));
+	textFont->setOverline(bool(extra.contains(i18n("overline"))));
+	textFont->setStrikeOut(bool(extra.contains(i18n("strikeout"))));
 }
 
 void Canvas::slotReset()
