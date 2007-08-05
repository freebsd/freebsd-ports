$FreeBSD$

--- ../../j2se/src/solaris/classes/sun/security/smartcardio/PlatformPCSC.java.orig	Sun Jul 29 23:03:30 2007
+++ ../../j2se/src/solaris/classes/sun/security/smartcardio/PlatformPCSC.java	Sun Jul 29 23:03:30 2007
@@ -32,7 +32,7 @@
     private final static String PROP_NAME = "sun.security.smartcardio.library";
 
     private final static String LIB1 = "/usr/$LIBISA/libpcsclite.so";
-    private final static String LIB2 = "/usr/local/$LIBISA/libpcsclite.so";
+    private final static String LIB2 = "%%LOCALBASE%%/$LIBISA/libpcsclite.so";
 
     PlatformPCSC() {
 	// empty
