--- arduino-core/src/processing/app/BaseNoGui.java.orig	2017-03-16 17:38:01 UTC
+++ arduino-core/src/processing/app/BaseNoGui.java
@@ -688,7 +688,7 @@ public class BaseNoGui {
       if (installedFolder != null) {
         toolPath = installedFolder.getAbsolutePath();
       } else {
-        toolPath = Constants.PREF_REMOVE_PLACEHOLDER;
+        toolPath = "/usr/local";
       }
       String toolName = tool.getName();
       String toolVersion = tool.getVersion();
