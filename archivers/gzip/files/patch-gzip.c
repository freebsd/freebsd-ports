--- gzip.c.orig	Sat Sep 28 09:38:43 2002
+++ gzip.c	Sat Jun 18 16:12:37 2005
@@ -875,8 +875,11 @@
     }
 
     close(ifd);
-    if (!to_stdout && close(ofd)) {
-	write_error();
+    if (!to_stdout) {
+        /* Copy modes, times, ownership, and remove the input file */
+        copy_stat(&istat);
+        if (close(ofd))
+	    write_error();
     }
     if (method == -1) {
 	if (!to_stdout) xunlink (ofname);
@@ -896,10 +899,6 @@
 	}
 	fprintf(stderr, "\n");
     }
-    /* Copy modes, times, ownership, and remove the input file */
-    if (!to_stdout) {
-	copy_stat(&istat);
-    }
 }
 
 /* ========================================================================
@@ -1317,6 +1316,7 @@
 		/* Copy the base name. Keep a directory prefix intact. */
                 char *p = base_name (ofname);
                 char *base = p;
+		char *base2;
 		for (;;) {
 		    *p = (char)get_char();
 		    if (*p++ == '\0') break;
@@ -1324,6 +1324,8 @@
 			error("corrupted input -- file name too large");
 		    }
 		}
+		base2 = basename (base);
+		strcpy(base, base2);
                 /* If necessary, adapt the name to local OS conventions: */
                 if (!list) {
                    MAKE_LEGAL_NAME(base);
@@ -1725,7 +1727,7 @@
     reset_times(ofname, ifstat);
 #endif
     /* Copy the protection modes */
-    if (chmod(ofname, ifstat->st_mode & 07777)) {
+    if (fchmod(ofd, ifstat->st_mode & 07777)) {
 	int e = errno;
 	WARN((stderr, "%s: ", progname));
 	if (!quiet) {
@@ -1734,7 +1736,7 @@
 	}
     }
 #ifndef NO_CHOWN
-    chown(ofname, ifstat->st_uid, ifstat->st_gid);  /* Copy ownership */
+    (void) fchown(ofd, ifstat->st_uid, ifstat->st_gid);  /* Copy ownership */
 #endif
     remove_ofname = 0;
     /* It's now safe to remove the input file: */
