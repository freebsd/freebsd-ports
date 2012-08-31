--- uartlirc_tty.c.orig
+++ uartlirc_tty.c
@@ -55,7 +55,7 @@ static cn_init_t uartlirc_cninit;
 static cn_term_t uartlirc_cnterm;
 static cn_getc_t uartlirc_cngetc;
 static cn_putc_t uartlirc_cnputc;
-#if __FreeBSD_version >= 1000000
+#if __FreeBSD_version >= 900506
 static cn_grab_t uartlirc_cngrab;
 static cn_ungrab_t uartlirc_cnungrab;
 #endif
@@ -112,7 +112,7 @@ uartlirc_cnterm(struct consdev *cp)
 	uartlirc_term(cp->cn_arg);
 }
 
-#if __FreeBSD_version >= 1000000
+#if __FreeBSD_version >= 900506
 static void
 uartlirc_cngrab(struct consdev *cp)
 {
