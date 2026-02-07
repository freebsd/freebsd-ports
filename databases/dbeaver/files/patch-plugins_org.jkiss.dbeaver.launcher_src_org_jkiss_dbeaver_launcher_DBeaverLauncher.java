--- plugins/org.jkiss.dbeaver.launcher/src/org/jkiss/dbeaver/launcher/DBeaverLauncher.java.orig	2025-07-18 15:47:12 UTC
+++ plugins/org.jkiss.dbeaver.launcher/src/org/jkiss/dbeaver/launcher/DBeaverLauncher.java
@@ -392,6 +392,8 @@ public class DBeaverLauncher {
             return Constants.WS_WIN32;
         if (osName.equals(Constants.OS_LINUX))
             return Constants.WS_GTK;
+        if (osName.equals(Constants.OS_FREEBSD))
+            return Constants.WS_GTK;
         if (osName.equals(Constants.OS_MACOSX))
             return Constants.WS_COCOA;
         if (osName.equals(Constants.OS_HPUX))
@@ -421,6 +423,8 @@ public class DBeaverLauncher {
             return Constants.OS_SOLARIS;
         if (osName.equalsIgnoreCase(Constants.INTERNAL_OS_LINUX))
             return Constants.OS_LINUX;
+        if (osName.equalsIgnoreCase(Constants.INTERNAL_OS_FREEBSD))
+            return Constants.OS_FREEBSD;
         if (osName.equalsIgnoreCase(Constants.INTERNAL_OS_QNX))
             return Constants.OS_QNX;
         if (osName.equalsIgnoreCase(Constants.INTERNAL_OS_AIX))
