--- modules/gsl.lsp.orig
+++ modules/gsl.lsp
@@ -169,6 +169,7 @@
 		(= ostype "Win32") "libgsl-0.dll" ; 32-bit
 		(= ostype "OSX")   "libgsl.dylib" ; 32-bit
 		(= ostype "Linux") "/usr/local/lib/libgsl.so" ; 32-bit or 64-bit
+		(= ostype "BSD") "/usr/local/lib/libgsl.so" ; 32-bit or 64-bit
 	))
 
 ; load libgslcblas which contans functions referenced by libgsl
@@ -179,6 +180,7 @@
 (if 
     (= ostype "OSX") (import "libgslcblas.dylib" "cblas_sdsdot")
     (= ostype "Linux") (import "/usr/local/lib/libgslcblas.so" "cblas_sdsdot")
+    (= ostype "BSD") (import "/usr/local/lib/libgslcblas.so" "cblas_sdsdot")
 )
     
 ; structs are defined but only needed for debugging, instead use "void*"
