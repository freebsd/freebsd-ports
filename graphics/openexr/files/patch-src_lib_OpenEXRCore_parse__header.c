--- src/lib/OpenEXRCore/parse_header.c.orig	2026-11-20 21:45:13 UTC
+++ src/lib/OpenEXRCore/parse_header.c
@@ -772,7 +772,7 @@ extract_attr_bytes(
         return ctxt->print_error (
             ctxt,
             EXR_ERR_ATTR_SIZE_MISMATCH,
-            "Attribute '%s': Invalid size %d (exp '%s' size >= %ld)",
+            "Attribute '%s': Invalid size %d (exp '%s' size >= %zu)",
             aname,
             attrsz,
             tname,
