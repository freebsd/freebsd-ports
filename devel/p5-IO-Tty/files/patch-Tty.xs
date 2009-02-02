--- Tty.xs
+++ Tty.xs
@@ -453,6 +453,18 @@
 #if defined(HAVE_PTSNAME) || defined(HAVE_PTSNAME_R)
 /* we don't need to try these if we don't have a way to get the pty names */
 
+#if defined(HAVE_POSIX_OPENPT)
+#if PTY_DEBUG
+	if (print_debug)
+	  fprintf(stderr, "trying posix_openpt()...\n");
+#endif
+	*ptyfd = posix_openpt(O_RDWR|O_NOCTTY);
+	if (*ptyfd >= 0 && open_slave(ptyfd, ttyfd, namebuf, namebuflen))
+	    break;		/* got one */
+	if (PL_dowarn)
+	    warn("pty_allocate(nonfatal): posix_openpt(): %.100s", strerror(errno));
+#endif /* defined(HAVE_POSIX_OPENPT) */
+
 #if defined(HAVE_GETPT)
 	/* glibc defines this */
 #if PTY_DEBUG
