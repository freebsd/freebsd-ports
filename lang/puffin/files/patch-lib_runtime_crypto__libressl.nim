--- lib/runtime/crypto_libressl.nim.orig	2026-10-31 12:04:23 UTC
+++ lib/runtime/crypto_libressl.nim
@@ -123,7 +123,8 @@ when awktuaUseHostLibcrypto:
     "if command -v pkg-config >/dev/null 2>&1; then " &
     "pkg-config --silence-errors --libs libcrypto 2>/dev/null; fi"))
   const cryptoLinkFlags* =
-    (if pkgLibsProbe.len > 0: pkgLibsProbe else: "-lcrypto")
+    (if pkgLibsProbe.len > 0: pkgLibsProbe else: "-lcrypto") & " " &
+    strip(gorge("pkg-config --silence-errors --libs libsodium sqlite3 libzstd bzip2"))
     ## Linker flags the HOST-OVERRIDE build needs (e.g. "-lcrypto"). The
     ## {.passL.} below covers every Nim-linked target, but a static .a records
     ## no link flags, so the emit-C link step (autoaot.nim) appends these when
