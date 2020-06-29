Obtained from:  https://git.archlinux.org/svntogit/packages.git/tree/trunk/qtcreator-clang-libs.patch?h=packages/qtcreator

--- src/shared/clang/clang_installation.pri.orig	2020-06-22 04:41:41 UTC
+++ src/shared/clang/clang_installation.pri
@@ -133,7 +133,8 @@ defineReplace(extractWarnings) {
 
 CLANGTOOLING_LIBS=-lclangTooling -lclangIndex -lclangFrontend -lclangParse -lclangSerialization \
                   -lclangSema -lclangEdit -lclangAnalysis -lclangDriver -lclangDynamicASTMatchers \
-                  -lclangASTMatchers -lclangToolingCore -lclangAST -lclangLex -lclangBasic
+                  -lclangASTMatchers -lclangToolingCore -lclangAST -lclangLex -lclangBasic \
+                  -lclang-cpp
 win32:CLANGTOOLING_LIBS += -lversion
 
 BIN_EXTENSION =
@@ -207,7 +208,8 @@ isEmpty(LLVM_VERSION) {
     isEmpty(QTC_CLANG_BUILDMODE_MISMATCH)|!equals(QTC_CLANG_BUILDMODE_MISMATCH, 1) {
         CLANGFORMAT_MAIN_HEADER = $$LLVM_INCLUDEPATH/clang/Format/Format.h
         exists($$CLANGFORMAT_MAIN_HEADER) {
-            CLANGFORMAT_LIBS=-lclangFormat -lclangToolingInclusions -lclangToolingCore -lclangRewrite -lclangLex -lclangBasic
+            CLANGFORMAT_LIBS=-lclangFormat -lclangToolingInclusions -lclangToolingCore -lclangRewrite -lclangLex -lclangBasic \
+                             -lclang-cpp
             ALL_CLANG_LIBS=-lclangFormat -lclangToolingInclusions -lclangTooling -lclangToolingCore \
                            -lclangRewrite -lclangIndex -lclangFrontend -lclangParse -lclangSerialization \
                            -lclangSema -lclangEdit -lclangAnalysis -lclangDriver -lclangDynamicASTMatchers \
