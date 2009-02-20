
$FreeBSD$

--- tools/clang/lib/Basic/Targets.cpp.orig
+++ tools/clang/lib/Basic/Targets.cpp
@@ -1012,7 +1012,7 @@
     return new SparcV8TargetInfo(T);
   }
 
-  if (T.find("x86_64-") == 0) {
+  if (T.find("x86_64-") == 0 || T.find("amd64-") == 0) {
     if (isDarwin)
       return new DarwinX86_64TargetInfo(T);
     if (isLinux)
