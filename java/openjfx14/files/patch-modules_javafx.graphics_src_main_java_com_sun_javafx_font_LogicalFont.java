--- modules/javafx.graphics/src/main/java/com/sun/javafx/font/LogicalFont.java.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.graphics/src/main/java/com/sun/javafx/font/LogicalFont.java
@@ -175,7 +175,7 @@ public class LogicalFont implements CompositeFontResou
             styleName = STYLE_BOLD_ITALIC;
         }
         fullName = familyName + " " + styleName;
-        if (PrismFontFactory.isLinux) {
+        if (PrismFontFactory.isLinux || PrismFontFactory.isFreeBSD) {
             FontConfigManager.FcCompFont fcCompFont =
                 FontConfigManager.getFontConfigFont(family, bold, italic);
             physicalFullName = fcCompFont.firstFont.fullName;
