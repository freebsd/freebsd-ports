--- src/java/jssc/SerialPort.java.orig	2016-10-24 19:44:26 UTC
+++ src/java/jssc/SerialPort.java
@@ -264,7 +264,8 @@ public class SerialPort {
         checkPortOpened("setEventsMask()");
         if(SerialNativeInterface.getOsType() == SerialNativeInterface.OS_LINUX ||
            SerialNativeInterface.getOsType() == SerialNativeInterface.OS_SOLARIS ||
-           SerialNativeInterface.getOsType() == SerialNativeInterface.OS_MAC_OS_X){//since 0.9.0
+           SerialNativeInterface.getOsType() == SerialNativeInterface.OS_MAC_OS_X ||
+	   SerialNativeInterface.getOsType() == SerialNativeInterface.OS_FREEBSD){//since 0.9.0
             linuxMask = mask;
             if(mask > 0){
                 maskAssigned = true;
@@ -298,7 +299,8 @@ public class SerialPort {
         checkPortOpened("getEventsMask()");
         if(SerialNativeInterface.getOsType() == SerialNativeInterface.OS_LINUX ||
            SerialNativeInterface.getOsType() == SerialNativeInterface.OS_SOLARIS ||
-           SerialNativeInterface.getOsType() == SerialNativeInterface.OS_MAC_OS_X){//since 0.9.0
+           SerialNativeInterface.getOsType() == SerialNativeInterface.OS_MAC_OS_X ||
+	   SerialNativeInterface.getOsType() == SerialNativeInterface.OS_FREEBSD){//since 0.9.0
             return linuxMask;
         }
         return serialInterface.getEventsMask(portHandle);
@@ -1041,7 +1043,8 @@ public class SerialPort {
     private EventThread getNewEventThread() {
         if(SerialNativeInterface.getOsType() == SerialNativeInterface.OS_LINUX ||
            SerialNativeInterface.getOsType() == SerialNativeInterface.OS_SOLARIS ||
-           SerialNativeInterface.getOsType() == SerialNativeInterface.OS_MAC_OS_X){//since 0.9.0
+           SerialNativeInterface.getOsType() == SerialNativeInterface.OS_MAC_OS_X ||
+	   SerialNativeInterface.getOsType() == SerialNativeInterface.OS_FREEBSD){//since 0.9.0
             return new LinuxEventThread();
         }
         return new EventThread();
