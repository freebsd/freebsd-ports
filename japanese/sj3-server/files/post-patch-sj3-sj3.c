--- sj3/sj3.c.orig2	2013-05-04 16:52:58.000000000 +0900
+++ sj3/sj3.c	2013-05-04 16:53:34.000000000 +0900
@@ -829,6 +829,8 @@
 		aprintf ("%s:\tmakeutx failed\r\n", progname);
 #endif /* SYSV_UTMP */
 #else /* SYSV_TERMIOS */
+/* XXX */
+#if __FreeBSD_version <= 900006
 	struct utmp		Utmp;
 	char		*p;
 /*
@@ -863,6 +865,7 @@
 
 	getslave ();
 #endif /* SYSV_TERMIOS */
+#endif
 	(void) close (master);
 	dup2 (slave, 0);
 	dup2 (slave, 1);
@@ -870,11 +873,14 @@
 	(void) close (slave);
 
 #ifndef SYSV_TERMIOS
+/* XXX */
+#if __FreeBSD_version <= 900006
 	if (Ttyslot > 0 && (f = open (_PATH_UTMP, 1)) >= 0) {
 		lseek (f, (long) (Ttyslot * sizeof (Utmp)), 0);
 		write (f, (char *)&Utmp, sizeof (Utmp));
 		close (f);
 	}
+#endif
 #endif /* SYSV_TERMIOS */
 
 	setgid (getgid ());
@@ -1227,6 +1233,8 @@
 void
 clearutmpentry ()
 {
+/* XXX */
+#if __FreeBSD_version <= 900006
 	int			f;
 	struct utmp		Utmp;
 
@@ -1240,7 +1248,10 @@
 		write (f, (char *)&Utmp, sizeof (Utmp));
 		close (f);
 	}
+#else
+	return;
 }
+#endif
 #endif /* SYSV_UTMP */
 #endif /* SVR4 */
 
