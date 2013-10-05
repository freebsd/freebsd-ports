--- src/com/sun/jna/NativeLibrary.java.orig	2013-07-04 14:42:30.000000000 -0400
+++ src/com/sun/jna/NativeLibrary.java	2013-10-04 17:28:07.000000000 -0400
@@ -203,7 +203,7 @@
                 }
                 catch(UnsatisfiedLinkError e2) { e = e2; }
             }
-            else if (Platform.isLinux()) {
+            else if (Platform.isLinux() || Platform.isFreeBSD()) {
                 //
                 // Failed to load the library normally - try to match libfoo.so.*
                 //
@@ -382,7 +382,7 @@
 
         // Use current process to load libraries we know are already
         // loaded by the VM to ensure we get the correct version
-        if ((Platform.isLinux() || Platform.isAIX())
+        if ((Platform.isLinux() || Platform.isFreeBSD() || Platform.isAIX())
             && Platform.C_LIBRARY_NAME.equals(libraryName)) {
             libraryName = null;
         }
@@ -702,7 +702,7 @@
             }
             return name;
         }
-        else if (Platform.isLinux()) {
+        else if (Platform.isLinux() || Platform.isFreeBSD()) {
             if (isVersionedName(libName) || libName.endsWith(".so")) {
                 // A specific version was requested - use as is for search
                 return libName;
