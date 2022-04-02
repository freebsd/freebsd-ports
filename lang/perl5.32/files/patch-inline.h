--- inline.h.orig	2020-12-18 10:04:36 UTC
+++ inline.h
@@ -434,9 +434,9 @@ Perl_is_utf8_invariant_string_loc(const U8* const s, S
  * or'ing together the lowest bits of 'x'.  Hopefully the final term gets
  * optimized out completely on a 32-bit system, and its mask gets optimized out
  * on a 64-bit system */
-#  define PERL_IS_SUBWORD_ADDR(x) (1 & (       PTR2nat(x)                     \
-                                      |   (  PTR2nat(x) >> 1)                 \
-                                      | ( ( (PTR2nat(x)                       \
+#  define PERL_IS_SUBWORD_ADDR(x) (1 & (       (size_t)PTR2nat(x)                     \
+                                      |   (  (size_t)PTR2nat(x) >> 1)                 \
+                                      | ( ( (size_t)(PTR2nat(x)                       \
                                            & PERL_WORD_BOUNDARY_MASK) >> 2))))
 
 #ifndef EBCDIC
@@ -1801,7 +1801,7 @@ Perl_utf8n_to_uvchr_msgs(const U8 *s,
     const U8 * const s0 = s;
     const U8 * send = s0 + curlen;
     UV uv = 0;      /* The 0 silences some stupid compilers */
-    UV state = 0;
+    UVINT state = 0;
 
     PERL_ARGS_ASSERT_UTF8N_TO_UVCHR_MSGS;
 
@@ -1811,7 +1811,7 @@ Perl_utf8n_to_uvchr_msgs(const U8 *s,
      * cases. */
 
     while (s < send && LIKELY(state != 1)) {
-        UV type = PL_strict_utf8_dfa_tab[*s];
+        UVINT type = PL_strict_utf8_dfa_tab[*s];
 
         uv = (state == 0)
              ?  ((0xff >> type) & NATIVE_UTF8_TO_I8(*s))
