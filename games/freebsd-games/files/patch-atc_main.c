Index: atc/main.c
@@ -173,6 +173,15 @@
 	ioctl(fileno(stdin), TCSETAW, &tty_new);
 #endif
 
+#ifdef POSIX
+	tcgetattr(fileno(stdin), &tty_start);
+	bcopy(&tty_start, &tty_new, sizeof(tty_new));
+	tty_new.c_lflag &= ~ICANON;
+	tty_new.c_lflag &= ~ECHO;
+	tty_new.c_cc[VMIN] = 1;
+	tty_new.c_cc[VTIME] = 0;
+	tcsetattr(fileno(stdin), TCSANOW, &tty_new);
+#endif
 	signal(SIGALRM, update);
 
 #ifdef BSD
@@ -185,6 +194,9 @@
 #ifdef SYSV
 	alarm(sp->update_secs);
 #endif
+#ifdef POSIX
+	alarm(sp->update_secs);
+#endif
 
 	for (;;) {
 		if (getcommand() != 1)
@@ -198,6 +210,9 @@
 #ifdef SYSV
 			alarm(0);
 #endif
+#ifdef POSIX
+			alarm(0);
+#endif
 
 			update();
 
@@ -209,6 +224,9 @@
 			setitimer(ITIMER_REAL, &itv, NULL);
 #endif
 #ifdef SYSV
+			alarm(sp->update_secs);
+#endif
+#ifdef POSIX
 			alarm(sp->update_secs);
 #endif
 		}
