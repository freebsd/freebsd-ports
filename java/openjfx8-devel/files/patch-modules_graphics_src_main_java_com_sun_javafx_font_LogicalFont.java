--- modules/graphics/src/main/java/com/sun/javafx/font/LogicalFont.java.orig	2019-07-22 19:00:13 UTC
+++ modules/graphics/src/main/java/com/sun/javafx/font/LogicalFont.java
@@ -175,7 +175,7 @@ public class LogicalFont implements CompositeFontResou
             styleName = STYLE_BOLD_ITALIC;
         }
         fullName = familyName + " " + styleName;
-        if (PrismFontFactory.isLinux) {
+        if (PrismFontFactory.isLinux || PrismFontFactory.isFreeBSD) {
             FontConfigManager.FcCompFont fcCompFont =
                 FontConfigManager.getFontConfigFont(family, bold, italic);
             physicalFullName = fcCompFont.firstFont.fullName;
