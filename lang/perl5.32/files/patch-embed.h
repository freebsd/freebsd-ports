--- embed.h.orig	2020-12-18 10:04:36 UTC
+++ embed.h
@@ -1906,7 +1906,7 @@
 #define sv_pos_u2b_forwards	S_sv_pos_u2b_forwards
 #define sv_pos_u2b_midway	S_sv_pos_u2b_midway
 #define sv_unglob(a,b)		S_sv_unglob(aTHX_ a,b)
-#define uiv_2buf		S_uiv_2buf
+#define uivint_2buf		S_uivint_2buf
 #define utf8_mg_len_cache_update(a,b,c)	S_utf8_mg_len_cache_update(aTHX_ a,b,c)
 #define utf8_mg_pos_cache_update(a,b,c,d,e)	S_utf8_mg_pos_cache_update(aTHX_ a,b,c,d,e)
 #define visit(a,b,c)		S_visit(aTHX_ a,b,c)
