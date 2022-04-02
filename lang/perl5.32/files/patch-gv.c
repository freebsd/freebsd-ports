--- gv.c.orig	2020-12-18 10:04:36 UTC
+++ gv.c
@@ -2063,7 +2063,7 @@ S_gv_magicalize(pTHX_ GV *gv, HV *stash, const char *n
                     AV* const av = GvAVn(gv);
                     const Size_t n = *name;
 
-                    sv_magic(MUTABLE_SV(av), (SV*)n, PERL_MAGIC_regdata, NULL, 0);
+                    sv_magic(MUTABLE_SV(av), (SV*)(IV)n, PERL_MAGIC_regdata, NULL, 0);
                     SvREADONLY_on(av);
 
                     require_tie_mod_s(gv, '+', "Tie::Hash::NamedCapture",0);
@@ -2233,7 +2233,7 @@ S_gv_magicalize(pTHX_ GV *gv, HV *stash, const char *n
                 AV* const av = GvAVn(gv);
                 const Size_t n = *name;
 
-                sv_magic(MUTABLE_SV(av), (SV*)n, PERL_MAGIC_regdata, NULL, 0);
+                sv_magic(MUTABLE_SV(av), (SV*)(UV)n, PERL_MAGIC_regdata, NULL, 0);
                 SvREADONLY_on(av);
             }
             break;
