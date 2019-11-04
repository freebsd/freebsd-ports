Remove compile time information (reproducible builds)

--- perl.c.orig	2019-11-04 11:00:14 UTC
+++ perl.c
@@ -2004,23 +2004,7 @@ S_Internals_V(pTHX_ CV *cv)
     PUSHs(Perl_newSVpvn_flags(aTHX_ non_bincompat_options,
 			      sizeof(non_bincompat_options) - 1, SVs_TEMP));
 
-#ifndef PERL_BUILD_DATE
-#  ifdef __DATE__
-#    ifdef __TIME__
-#      define PERL_BUILD_DATE __DATE__ " " __TIME__
-#    else
-#      define PERL_BUILD_DATE __DATE__
-#    endif
-#  endif
-#endif
-
-#ifdef PERL_BUILD_DATE
-    PUSHs(Perl_newSVpvn_flags(aTHX_
-			      STR_WITH_LEN("Compiled at " PERL_BUILD_DATE),
-			      SVs_TEMP));
-#else
     PUSHs(&PL_sv_undef);
-#endif
 
     for (i = 1; i <= local_patch_count; i++) {
 	/* This will be an undef, if PL_localpatches[i] is NULL.  */
