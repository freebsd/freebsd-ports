--- jdk/src/solaris/classes/sun/print/UnixPrintServiceLookup.java
+++ jdk/src/solaris/classes/sun/print/UnixPrintServiceLookup.java
@@ -140,12 +140,12 @@
     static int cmdIndex = UNINITIALIZED;
 
     String[] lpcFirstCom = {
-        "/usr/sbin/lpc status | grep : | sed -ne '1,1 s/://p'",
+        "/usr/sbin/lpc status all | grep ':$' | sed -ne '1,1 s/://p'",
         "/usr/sbin/lpc status | grep -E '^[ 0-9a-zA-Z_-]*@' | awk -F'@' '{print $1}'"
     };
 
     String[] lpcAllCom = {
-        "/usr/sbin/lpc status all | grep : | sed -e 's/://'",
+        "/usr/sbin/lpc status all | grep ':$' | sed -e 's/://'",
         "/usr/sbin/lpc status all | grep -E '^[ 0-9a-zA-Z_-]*@' | awk -F'@' '{print $1}' | sort"
     };
 
