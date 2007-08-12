--- xsim/ic.h.orig	2007-08-12 15:40:46.000000000 +0200
+++ xsim/ic.h	2007-08-12 15:42:35.000000000 +0200
@@ -76,7 +76,7 @@
 	void set_im(TIM * val);
 
 	TIMC * get_imc();
-	int has_imc() { return (int)imc; }
+	intptr_t has_imc() { return (intptr_t)imc; }
 
 	void init(int init_mode, TIM * val);
 
