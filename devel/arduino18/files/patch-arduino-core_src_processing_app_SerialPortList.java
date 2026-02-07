--- arduino-core/src/processing/app/SerialPortList.java.orig	2019-03-12 21:32:52 UTC
+++ arduino-core/src/processing/app/SerialPortList.java
@@ -66,6 +66,11 @@ public class SerialPortList {
                 PORTNAMES_PATH = "";
                 break;
             }
+            case SerialNativeInterface.OS_FREEBSD: {
+                PORTNAMES_REGEXP = Pattern.compile("cuaU[0-9]{1,3}$");
+                PORTNAMES_PATH = "/dev/";
+                break;
+            }
             default: {
                 PORTNAMES_REGEXP = null;
                 PORTNAMES_PATH = null;
