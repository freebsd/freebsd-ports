--- dist/Devel-PPPort/parts/embed.fnc.orig	2020-12-18 10:04:36 UTC
+++ dist/Devel-PPPort/parts/embed.fnc
@@ -2913,7 +2913,7 @@ pX	|void	|sv_del_backref	|NN SV *const tsv|NN SV *cons
 
 pX	|void	|sv_del_backref	|NN SV *const tsv|NN SV *const sv
 #if defined(PERL_IN_SV_C)
-TiR	|char *	|uiv_2buf	|NN char *const buf|const IV iv|UV uv|const int is_uv|NN char **const peob
+TiR	|char *	|uivint_2buf	|NN char *const buf|const IVINT iv|UVINT uv|const int is_uv|NN char **const peob
 i	|void	|sv_unglob	|NN SV *const sv|U32 flags
 S	|const char *|sv_display	|NN SV *const sv|NN char *tmpbuf|STRLEN tmpbuf_size
 S	|void	|not_a_number	|NN SV *const sv
