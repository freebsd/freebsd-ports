
$FreeBSD$

--- erts/emulator/beam/erl_process_dump.c.orig
+++ erts/emulator/beam/erl_process_dump.c
@@ -399,9 +399,11 @@
 static void
 dump_externally(int to, void *to_arg, Eterm term)
 {
-    byte sbuf[1024]; /* encode and hope for the best ... */
-    byte* s; 
-    byte* p;
+    byte *sbuf, *s, *p;
+    unsigned size;
+
+    size = encode_size_struct(term, TERM_TO_BINARY_DFLAGS);
+    sbuf = (byte *) erts_alloc(ERTS_ALC_T_TMP, size);
 
     s = p = sbuf;
     erts_to_external_format(NULL, term, &p, NULL, NULL);
@@ -409,4 +411,6 @@
     while (s < p) {
 	erts_print(to, to_arg, "%02X", *s++);
     }
+
+    erts_free(ERTS_ALC_T_TMP, (void *) sbuf);
 }
