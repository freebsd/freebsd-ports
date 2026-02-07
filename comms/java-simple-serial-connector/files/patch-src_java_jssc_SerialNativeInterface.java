--- src/java/jssc/SerialNativeInterface.java.orig	2014-01-24 14:34:02 UTC
+++ src/java/jssc/SerialNativeInterface.java
@@ -43,6 +43,7 @@ public class SerialNativeInterface {
     public static final int OS_WINDOWS = 1;
     public static final int OS_SOLARIS = 2;//since 0.9.0
     public static final int OS_MAC_OS_X = 3;//since 0.9.0
+    public static final int OS_FREEBSD = 4;
 
     private static int osType = -1;
 
@@ -108,36 +109,16 @@ public class SerialNativeInterface {
             osName = "mac_os_x";
             osType = OS_MAC_OS_X;
         }//<- since 0.9.0
+        else if(osName.equals("FreeBSD")){
+	    osName = "freebsd";
+	    osType = OS_FREEBSD;
+	}
 
         if(architecture.equals("i386") || architecture.equals("i686")){
-            architecture = "x86";
+            architecture = "i386";
         }
         else if(architecture.equals("amd64") || architecture.equals("universal")){//os.arch "universal" since 2.6.0
-            architecture = "x86_64";
-        }
-        else if(architecture.equals("arm")) {//since 2.1.0
-            String floatStr = "sf";
-            if(javaLibPath.toLowerCase().contains("gnueabihf") || javaLibPath.toLowerCase().contains("armhf")){
-                floatStr = "hf";
-            }
-            else {
-                try {
-                    Process readelfProcess =  Runtime.getRuntime().exec("readelf -A /proc/self/exe");
-                    BufferedReader reader = new BufferedReader(new InputStreamReader(readelfProcess.getInputStream()));
-                    String buffer = "";
-                    while((buffer = reader.readLine()) != null && !buffer.isEmpty()){
-                        if(buffer.toLowerCase().contains("Tag_ABI_VFP_args".toLowerCase())){
-                            floatStr = "hf";
-                            break;
-                        }
-                    }
-                    reader.close();
-                }
-                catch (Exception ex) {
-                    //Do nothing
-                }
-            }
-            architecture = "arm" + floatStr;
+            architecture = "amd64";
         }
         
         libFolderPath = libRootFolder + fileSeparator + ".jssc" + fileSeparator + osName;
@@ -259,7 +240,7 @@ public class SerialNativeInterface {
     }
 
     /**
-     * Get OS type (OS_LINUX || OS_WINDOWS || OS_SOLARIS)
+     * Get OS type (OS_LINUX || OS_WINDOWS || OS_SOLARIS || OS_FREEBSD)
      * 
      * @since 0.8
      */
