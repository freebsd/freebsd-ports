--- modules/graphics/src/main/java/com/sun/prism/impl/PrismSettings.java.orig	2017-09-08 16:56:55 UTC
+++ modules/graphics/src/main/java/com/sun/prism/impl/PrismSettings.java
@@ -212,6 +212,8 @@ public final class PrismSettings {
                     tryOrderArr = new String[] { "es2" };
             } else if (PlatformUtil.isLinux()) {
                 tryOrderArr = new String[] { "es2", "sw" };
+            } else if (PlatformUtil.isFreeBSD()) {
+                tryOrderArr = new String[] { "es2", "sw" };
             } else {
                 tryOrderArr = new String[] { "sw" };
             }
