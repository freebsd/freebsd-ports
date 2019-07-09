From af76e728b3f309b6962847f06876e6c4c6a8c065 Mon Sep 17 00:00:00 2001
From: Justus Winter <justus@sequoia-pgp.org>
Date: Mon, 1 Jul 2019 12:05:09 +0200
Subject: [PATCH] Do not bind the openssl-compat interface.

  * In Nettle 3.5, the libdes/openssl compatibility interface is
    removed, breaking the build of nettle-sys.

  * Fix this by not binding any of the compatibility interfaces
    present in Nettle.

  * Fixes #4.

From 7ec219212af8c1331a645b5a153bc2271bef19e6 Mon Sep 17 00:00:00 2001
From: Justus Winter <justus@sequoia-pgp.org>
Date: Mon, 8 Jul 2019 11:55:37 +0200
Subject: [PATCH] Fix building against latest Nettle.

  - `nettle/nettle-stdint.h` is no longer distributed with Nettle.
    Dropping it from `bindgen-wrapper.h` does not change the generated
    bindings, hence we do not need to bump the major version.

  - Tested against Nettle revision
    eead7cfa32c341b5193a697273de9fc7336e694a.

  - Fixes #5.
--- cargo-crates/nettle-sys-1.0.1/bindgen-wrapper.h.orig	2017-11-30 11:38:42 UTC
+++ cargo-crates/nettle-sys-1.0.1/bindgen-wrapper.h
@@ -16,9 +16,7 @@
 #include <nettle/chacha.h>
 #include <nettle/ctr.h>
 #include <nettle/curve25519.h>
-#include <nettle/des-compat.h>
 #include <nettle/des.h>
-#include <nettle/dsa-compat.h>
 #include <nettle/dsa.h>
 #include <nettle/eax.h>
 #include <nettle/ecc-curve.h>
@@ -33,12 +31,10 @@
 #include <nettle/macros.h>
 #include <nettle/md2.h>
 #include <nettle/md4.h>
-#include <nettle/md5-compat.h>
 #include <nettle/md5.h>
 #include <nettle/memops.h>
 #include <nettle/memxor.h>
 #include <nettle/nettle-meta.h>
-#include <nettle/nettle-stdint.h>
 #include <nettle/nettle-types.h>
 #include <nettle/pbkdf2.h>
 #include <nettle/pgp.h>
