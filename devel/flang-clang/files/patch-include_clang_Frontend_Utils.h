--- include/clang/Frontend/Utils.h.orig	2019-10-20 18:47:05 UTC
+++ include/clang/Frontend/Utils.h
@@ -34,6 +34,7 @@
 namespace llvm {
 
 class Triple;
+class StringRef;
 
 namespace opt {
 
@@ -60,7 +61,6 @@ class PCHContainerReader;
 class Preprocessor;
 class PreprocessorOptions;
 class PreprocessorOutputOptions;
-class StringRef;
 
 /// Apply the header search options to get given HeaderSearch object.
 void ApplyHeaderSearchOptions(HeaderSearch &HS,
