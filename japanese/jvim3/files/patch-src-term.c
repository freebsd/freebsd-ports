--- src/term.c.orig	2025-12-15 09:04:17 UTC
+++ src/term.c
@@ -207,7 +207,9 @@ set_term(term)
 			T_CDL = TGETSTR("DL", &tp);
 			T_CS = TGETSTR("cs", &tp);
 			T_ED = TGETSTR("cl", &tp);
+#ifndef __FreeBSD__ /* by Satoshi TAOKA */
 			T_CI = TGETSTR("vi", &tp);
+#endif
 			T_CV = TGETSTR("ve", &tp);
 			T_CVV = TGETSTR("vs", &tp);
 			T_TP = TGETSTR("me", &tp);
