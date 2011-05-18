--- eperl_perl5.c.orig	2011-05-18 15:30:35.000000000 -0400
+++ eperl_perl5.c	2011-05-18 15:30:47.000000000 -0400
@@ -98,8 +98,8 @@
 void Perl5_SetScalar(char *pname, char *vname, char *vvalue)
 {
     ENTER;
-    save_hptr(&curstash); 
-    curstash = gv_stashpv(pname, TRUE);
+    save_hptr(&PL_curstash); 
+    PL_curstash = gv_stashpv(pname, TRUE);
     sv_setpv(perl_get_sv(vname, TRUE), vvalue);
     LEAVE;
     return;
