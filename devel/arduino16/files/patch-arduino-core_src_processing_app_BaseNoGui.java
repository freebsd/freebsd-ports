--- arduino-core/src/processing/app/BaseNoGui.java.orig	2016-09-21 10:09:37 UTC
+++ arduino-core/src/processing/app/BaseNoGui.java
@@ -851,7 +851,7 @@ public class BaseNoGui {
       if (installedFolder != null) {
         toolPath = installedFolder.getAbsolutePath();
       } else {
-        toolPath = Constants.PREF_REMOVE_PLACEHOLDER;
+        toolPath = "/usr/local";
       }
       String toolName = tool.getName();
       String toolVersion = tool.getVersion();
