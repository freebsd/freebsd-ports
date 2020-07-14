--- fvh/src/fbl_byacc.h.orig	2014-08-02 23:38:00 UTC
+++ fvh/src/fbl_byacc.h
@@ -119,5 +119,5 @@ extern void         fbl_select();
   extern          char * fbl_stostr __P((char *str));
 
   extern           void  fbl_y_error __P((char *str));
-  extern            long  fbl_y_lex __P(());
+  extern            int  fbl_y_lex __P(());
 
