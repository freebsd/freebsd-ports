--- src/dump_cds.c.orig	2021-02-12 16:29:40 UTC
+++ src/dump_cds.c
@@ -42,8 +42,8 @@
 #if HAVE_LIBTINYCBOR
 
 #include <stdlib.h>
-#if HAVE_CBOR_CBOR_H
-#include <cbor/cbor.h>
+#if HAVE_TINYCBOR_CBOR_H
+#include <tinycbor/cbor.h>
 #endif
 #if HAVE_CBOR_H
 #include <cbor.h>
