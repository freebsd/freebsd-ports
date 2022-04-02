--- proto.h.orig	2020-12-18 10:04:36 UTC
+++ proto.h
@@ -2873,7 +2873,7 @@ PERL_CALLCONV regnode*	Perl_regnext(pTHX_ regnode* p)
 			__attribute__warn_unused_result__;
 #define PERL_ARGS_ASSERT_REGNEXT
 
-PERL_CALLCONV void	Perl_repeatcpy(char* to, const char* from, I32 len, IV count);
+PERL_CALLCONV void	Perl_repeatcpy(char* to, const char* from, I32 len, IVINT count);
 #define PERL_ARGS_ASSERT_REPEATCPY	\
 	assert(to); assert(from)
 PERL_CALLCONV void	Perl_report_evil_fh(pTHX_ const GV *gv);
@@ -6374,9 +6374,9 @@ PERL_STATIC_INLINE void	S_sv_unglob(pTHX_ SV *const sv
 	assert(sv)
 #endif
 #ifndef PERL_NO_INLINE_FUNCTIONS
-PERL_STATIC_INLINE char *	S_uiv_2buf(char *const buf, const IV iv, UV uv, const int is_uv, char **const peob)
+PERL_STATIC_INLINE char *	S_uivint_2buf(char *const buf, const IVINT iv, UVINT uv, const int is_uv, char **const peob)
 			__attribute__warn_unused_result__;
-#define PERL_ARGS_ASSERT_UIV_2BUF	\
+#define PERL_ARGS_ASSERT_UIVINT_2BUF	\
 	assert(buf); assert(peob)
 #endif
 
