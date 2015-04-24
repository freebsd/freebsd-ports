--- Flags.xs.orig	2014-12-03 12:04:54 UTC
+++ Flags.xs
@@ -66,8 +66,13 @@ flagspv(o)
         if (o->op_folded)
             sv_catpv(RETVAL, ",FOLDED");
 #if (PERL_VERSION == 21 && PERL_SUBVERSION > 1) || PERL_VERSION >= 22
+#if (PERL_VERSION == 21 && PERL_SUBVERSION < 11)
         if (o->op_lastsib)
             sv_catpv(RETVAL, ",LASTSIB");
+#else
+        if (o->op_moresib)
+            sv_catpv(RETVAL, ",MORESIB");
+#endif
 #endif
 #endif
 #endif
