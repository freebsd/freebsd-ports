--- stdlib/OpenSSL_jll/src/OpenSSL_jll.jl.orig	2026-10-25 17:06:47 UTC
+++ stdlib/OpenSSL_jll/src/OpenSSL_jll.jl
@@ -31,8 +31,8 @@ else
     const libcrypto = "@rpath/libcrypto.3.dylib"
     const libssl = "@rpath/libssl.3.dylib"
 else
-    const libcrypto = "libcrypto.so.3"
-    const libssl = "libssl.so.3"
+    const libcrypto = "libcrypto.so"
+    const libssl = "libssl.so"
 end
 
 function __init__()
