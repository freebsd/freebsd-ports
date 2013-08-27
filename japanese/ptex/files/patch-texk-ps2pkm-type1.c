--- texk/ps2pkm/type1.c.orig	2013-08-27 19:21:53.000000000 +0900
+++ texk/ps2pkm/type1.c	2013-08-27 19:34:37.000000000 +0900
@@ -125,8 +125,10 @@
 #define CC IfTrace1(TRUE, "'%03o ", currentchar)
 
 #define Error {errflag = TRUE; return;}
+#define Errord {errflag = TRUE; return 0.0;}
  
 #define Error0(errmsg) { CC; IfTrace0(TRUE, errmsg); Error;}
+#define Error0d(errmsg) { CC; IfTrace0(TRUE, errmsg); Errord;}
  
 #define Error1(errmsg,arg) { CC; IfTrace1(TRUE, errmsg, arg); Error;}
  
@@ -800,7 +802,7 @@
 static DOUBLE PSFakePop ()
 {
   if (PSFakeTop >= 0) return(PSFakeStack[PSFakeTop--]);
-  else Error0("PSFakePop : Stack empty\n");
+  else Error0d("PSFakePop : Stack empty\n");
   /*NOTREACHED*/
 }
  
