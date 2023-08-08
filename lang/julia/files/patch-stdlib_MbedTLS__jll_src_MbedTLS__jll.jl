--- stdlib/MbedTLS_jll/src/MbedTLS_jll.jl.orig	2022-11-21 01:45:43 UTC
+++ stdlib/MbedTLS_jll/src/MbedTLS_jll.jl
@@ -31,9 +31,9 @@ else
     const libmbedtls = "@rpath/libmbedtls.14.dylib"
     const libmbedx509 = "@rpath/libmbedx509.1.dylib"
 else
-    const libmbedcrypto = "libmbedcrypto.so.7"
-    const libmbedtls = "libmbedtls.so.14"
-    const libmbedx509 = "libmbedx509.so.1"
+    const libmbedcrypto = "libmbedcrypto.so"
+    const libmbedtls = "libmbedtls.so"
+    const libmbedx509 = "libmbedx509.so"
 end
 
 function __init__()
