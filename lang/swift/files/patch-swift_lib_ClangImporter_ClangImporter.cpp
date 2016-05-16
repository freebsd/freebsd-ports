--- swift/lib/ClangImporter/ClangImporter.cpp.orig	2016-03-21 17:35:26 UTC
+++ swift/lib/ClangImporter/ClangImporter.cpp
@@ -332,7 +332,7 @@ getNormalInvocationArguments(std::vector
       // not import Objective-C modules.
       //
       // Just use the most feature-rich C language mode.
-      "-x", "c", "-std=gnu11",
+      "-x", "c", "-std=gnu11", "-I/usr/include"
     });
   }
 
@@ -376,7 +376,7 @@ getNormalInvocationArguments(std::vector
   } else {
     // On Darwin, Clang uses -isysroot to specify the include
     // system root. On other targets, it seems to use --sysroot.
-    if (triple.isOSDarwin()) {
+    if (triple.isOSDarwin() || triple.isOSFreeBSD()) {
       invocationArgStrs.push_back("-isysroot");
     } else {
       invocationArgStrs.push_back("--sysroot");
