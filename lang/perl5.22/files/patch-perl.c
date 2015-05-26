--- perl.c.orig	2015-04-15 07:47:18 UTC
+++ perl.c
@@ -1795,18 +1795,7 @@ S_Internals_V(pTHX_ CV *cv)
     PUSHs(Perl_newSVpvn_flags(aTHX_ non_bincompat_options,
 			      sizeof(non_bincompat_options) - 1, SVs_TEMP));
 
-#ifdef __DATE__
-#  ifdef __TIME__
-    PUSHs(Perl_newSVpvn_flags(aTHX_
-			      STR_WITH_LEN("Compiled at " __DATE__ " " __TIME__),
-			      SVs_TEMP));
-#  else
-    PUSHs(Perl_newSVpvn_flags(aTHX_ STR_WITH_LEN("Compiled on " __DATE__),
-			      SVs_TEMP));
-#  endif
-#else
     PUSHs(&PL_sv_undef);
-#endif
 
     for (i = 1; i <= local_patch_count; i++) {
 	/* This will be an undef, if PL_localpatches[i] is NULL.  */
