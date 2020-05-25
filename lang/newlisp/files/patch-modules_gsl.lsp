--- modules/gsl.lsp.orig	2019-05-12 16:44:17 UTC
+++ modules/gsl.lsp
@@ -171,6 +171,7 @@
 		(= ostype "Windows") "libgsl-0.dll" ; 32-bit or 64-bit
 		(= ostype "OSX")   "libgsl.dylib" ; 32-bit or 64-bit
 		(= ostype "Linux") "/usr/local/lib/libgsl.so" ; 32-bit or 64-bit
+		(= ostype "BSD") "/usr/local/lib/libgsl.so" ; 32-bit or 64-bit
 	))
 
 ; load libgslcblas which contans functions referenced by libgsl
@@ -181,6 +182,7 @@
 (if 
     (= ostype "OSX") (import "libgslcblas.dylib" "cblas_sdsdot")
     (= ostype "Linux") (import "/usr/local/lib/libgslcblas.so" "cblas_sdsdot")
+    (= ostype "BSD") (import "/usr/local/lib/libgslcblas.so" "cblas_sdsdot")
 )
     
 ; structs are defined but only needed for debugging, instead use "void*"
