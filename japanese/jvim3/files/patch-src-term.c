--- src/term.c.~1~	Thu Sep 17 11:58:38 1998
+++ src/term.c	Fri Sep 18 09:26:33 1998
@@ -207,7 +207,9 @@
 			T_CDL = TGETSTR("DL", &tp);
 			T_CS = TGETSTR("cs", &tp);
 			T_ED = TGETSTR("cl", &tp);
+#ifndef __FreeBSD__ /* by Satoshi TAOKA */
 			T_CI = TGETSTR("vi", &tp);
+#endif
 			T_CV = TGETSTR("ve", &tp);
 			T_CVV = TGETSTR("vs", &tp);
 			T_TP = TGETSTR("me", &tp);
