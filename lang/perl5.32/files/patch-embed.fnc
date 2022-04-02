--- embed.fnc.orig	2020-12-18 10:04:36 UTC
+++ embed.fnc
@@ -1523,7 +1523,7 @@ S	|OP*	|refkids	|NULLOK OP* o|I32 type
 S	|OP*	|refkids	|NULLOK OP* o|I32 type
 #endif
 
-ATp	|void	|repeatcpy	|NN char* to|NN const char* from|I32 len|IV count
+ATp	|void	|repeatcpy	|NN char* to|NN const char* from|I32 len|IVINT count
 AdTpP	|char*	|rninstr	|NN const char* big|NN const char* bigend \
 				|NN const char* little|NN const char* lend
 Apd	|Sighandler_t|rsignal	|int i|Sighandler_t t
@@ -2966,7 +2966,7 @@ pX	|void	|sv_del_backref	|NN SV *const tsv|NN SV *cons
 
 pX	|void	|sv_del_backref	|NN SV *const tsv|NN SV *const sv
 #if defined(PERL_IN_SV_C)
-TiR	|char *	|uiv_2buf	|NN char *const buf|const IV iv|UV uv|const int is_uv|NN char **const peob
+TiR	|char *	|uivint_2buf	|NN char *const buf|const IVINT iv|UVINT uv|const int is_uv|NN char **const peob
 i	|void	|sv_unglob	|NN SV *const sv|U32 flags
 S	|const char *|sv_display	|NN SV *const sv|NN char *tmpbuf|STRLEN tmpbuf_size
 S	|void	|not_a_number	|NN SV *const sv
