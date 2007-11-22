--- utils/hzimctrl.c.orig	2007-11-22 14:25:31.000000000 +0100
+++ utils/hzimctrl.c	2007-11-22 14:25:47.000000000 +0100
@@ -112,6 +112,11 @@
 char *setim = "\033]161;%s\007";	/* esc seq for set hz input method */
 char *setparam = "\033]162;%s\007";	/* esc seq for set input param */
 
+#ifdef CANT_OPEN_DEV_TTY
+	extern char *ttyname();
+#endif
+	static void Usage();
+
 /*
    set input method 
  */
@@ -127,10 +132,6 @@
 #endif /* USE_SYSV_TERMIO */
 	char buf[BUFSIZ];
 	char *name_of_tty;
-#ifdef CANT_OPEN_DEV_TTY
-	extern char *ttyname();
-#endif
-	static void Usage();
 
 	ptr = strrchr(myname = argv[0], '/');
 	if (ptr)
