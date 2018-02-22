--- compiler/main/SysTools.hs.orig	2017-08-12 09:25:57 UTC
+++ compiler/main/SysTools.hs
@@ -907,6 +907,9 @@ getCompilerInfo' dflags = do
         -- Regular clang
         | any ("clang version" `isInfixOf`) stde =
           return Clang
+        -- FreeBSD clang
+        | any ("FreeBSD clang version" `isInfixOf`) stde =
+          return Clang
         -- XCode 5.1 clang
         | any ("Apple LLVM version 5.1" `isPrefixOf`) stde =
           return AppleClang51
