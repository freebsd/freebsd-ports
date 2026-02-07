--- src/java/jssc/SerialPortList.java.orig	2016-10-24 19:46:27 UTC
+++ src/java/jssc/SerialPortList.java
@@ -57,6 +57,11 @@ public class SerialPortList {
                 PORTNAMES_PATH = "/dev/";
                 break;
             }
+            case SerialNativeInterface.OS_FREEBSD: {
+                PORTNAMES_REGEXP = Pattern.compile("cuaU[0-9]{1,3}$");
+                PORTNAMES_PATH = "/dev/";
+                break;
+            }
             case SerialNativeInterface.OS_WINDOWS: {
                 PORTNAMES_REGEXP = Pattern.compile("");
                 PORTNAMES_PATH = "";
