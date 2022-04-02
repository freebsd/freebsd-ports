--- ext/B/B.xs.orig	2020-12-18 10:04:36 UTC
+++ ext/B/B.xs
@@ -1180,7 +1180,7 @@ string(o, cv)
             {
                 struct op_argcheck_aux *p = (struct op_argcheck_aux*)aux;
                 ret = Perl_newSVpvf(aTHX_ "%" IVdf ",%" IVdf,
-                                    p->params, p->opt_params);
+                                    (IV)p->params, (IV)p->opt_params);
                 if (p->slurpy)
                     Perl_sv_catpvf(aTHX_ ret, ",%c", p->slurpy);
                 ret = sv_2mortal(ret);
