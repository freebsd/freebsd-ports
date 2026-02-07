--- modules/javafx.graphics/src/main/java/com/sun/javafx/font/PrismFontFactory.java.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.graphics/src/main/java/com/sun/javafx/font/PrismFontFactory.java
@@ -51,6 +51,7 @@ public abstract class PrismFontFactory implements Font
     public static final boolean debugFonts;
     public static final boolean isWindows;
     public static final boolean isLinux;
+    public static final boolean isFreeBSD;
     public static final boolean isMacOSX;
     public static final boolean isIOS;
     public static final boolean isAndroid;
@@ -88,6 +89,7 @@ public abstract class PrismFontFactory implements Font
         isWindows = PlatformUtil.isWindows();
         isMacOSX  = PlatformUtil.isMac();
         isLinux   = PlatformUtil.isLinux();
+        isFreeBSD = PlatformUtil.isFreeBSD();
         isIOS     = PlatformUtil.isIOS();
         isAndroid = PlatformUtil.isAndroid();
         isEmbedded = PlatformUtil.isEmbedded();
@@ -164,7 +166,7 @@ public abstract class PrismFontFactory implements Font
     private static String getNativeFactoryName() {
         if (isWindows) return DW_FACTORY;
         if (isMacOSX || isIOS) return CT_FACTORY;
-        if (isLinux || isAndroid) return FT_FACTORY;
+        if (isLinux || isAndroid || isFreeBSD) return FT_FACTORY;
         return null;
     }
 
@@ -851,7 +853,7 @@ public abstract class PrismFontFactory implements Font
                         break;
                     }
                 }
-                if (fontResource == null && isLinux) {
+                if (fontResource == null && (isLinux || isFreeBSD)) {
                     String path = FontConfigManager.getDefaultFontPath();
                     if (path != null) {
                         fontResource = createFontResource(jreDefaultFontLC,
@@ -1770,7 +1772,7 @@ public abstract class PrismFontFactory implements Font
                                                       familyToFontListMap,
                                                       Locale.ENGLISH);
 
-            } else if (isLinux) {
+            } else if (isLinux || isFreeBSD) {
                 FontConfigManager.populateMaps(tmpFontToFileMap,
                                                fontToFamilyNameMap,
                                                familyToFontListMap,
