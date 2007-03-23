Index: atc/input.c
@@ -323,6 +323,10 @@
 			int aval;
 			aval = alarm(0);
 #endif
+#ifdef POSIX
+			int aval;
+			aval = alarm(0);
+#endif
 			if (fork() == 0)	/* child */
 			{
 				char *shell, *base;
@@ -358,6 +362,10 @@
 #endif
 #ifdef SYSV
 			ioctl(fileno(stdin), TCSETAW, &tty_new);
+			alarm(aval);
+#endif
+#ifdef POSIX
+			tcsetattr(fileno(stdin), TCSANOW, &tty_new);
 			alarm(aval);
 #endif
 		}
