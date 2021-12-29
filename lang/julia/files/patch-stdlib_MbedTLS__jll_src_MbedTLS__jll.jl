--- stdlib/MbedTLS_jll/src/MbedTLS_jll.jl.orig	2021-11-25 11:01:50 UTC
+++ stdlib/MbedTLS_jll/src/MbedTLS_jll.jl
@@ -31,9 +31,9 @@ elseif Sys.isapple()
     const libmbedtls = "@rpath/libmbedtls.13.dylib"
     const libmbedx509 = "@rpath/libmbedx509.1.dylib"
 else
-    const libmbedcrypto = "libmbedcrypto.so.5"
-    const libmbedtls = "libmbedtls.so.13"
-    const libmbedx509 = "libmbedx509.so.1"
+    const libmbedcrypto = "libmbedcrypto.so"
+    const libmbedtls = "libmbedtls.so"
+    const libmbedx509 = "libmbedx509.so"
 end
 
 function __init__()
