--- gzip.c.orig	Tue Mar 20 01:09:51 2007
+++ gzip.c	Tue Jun  5 21:43:50 2007
@@ -216,6 +216,8 @@
    suppresses a "Broken Pipe" message with some shells.  */
 static int volatile exiting_signal;
 
+/* If nonzero, unlink input file on exit. */
+static int remove_ifname = 1;
 /* If nonnegative, close this file descriptor and unlink ofname on error.  */
 static int volatile remove_ofname_fd = -1;
 
@@ -243,6 +245,7 @@
  /* {"encrypt",    0, 0, 'e'},    encrypt */
     {"force",      0, 0, 'f'}, /* force overwrite of output file */
     {"help",       0, 0, 'h'}, /* give help */
+    {"keep",       0, 0, 'k'}, /* keep (don't delete) input files */
  /* {"pkzip",      0, 0, 'k'},    force output in pkzip format */
     {"list",       0, 0, 'l'}, /* list .gz file contents */
     {"license",    0, 0, 'L'}, /* display software license */
@@ -319,6 +322,7 @@
  "  -f, --force       force overwrite of output file and compress links",
  "  -h, --help        give this help",
 /*  -k, --pkzip       force output in pkzip format */
+ "  -k, --keep        keep (don't delete) input files",
  "  -l, --list        list compressed file contents",
  "  -L, --license     display software license",
 #ifdef UNDOCUMENTED
@@ -423,7 +427,7 @@
     z_suffix = Z_SUFFIX;
     z_len = strlen(z_suffix);
 
-    while ((optc = getopt_long (argc, argv, "ab:cdfhH?lLmMnNqrS:tvVZ123456789",
+    while ((optc = getopt_long (argc, argv, "ab:cdfhH?klLmMnNqrS:tvVZ123456789",
 				longopts, (int *)0)) != -1) {
 	switch (optc) {
         case 'a':
@@ -446,6 +450,8 @@
 	    force++; break;
 	case 'h': case 'H':
 	    help(); do_exit(OK); break;
+	case 'k':
+	    remove_ifname = 0; break;
 	case 'l':
 	    list = decompress = to_stdout = 1; break;
 	case 'L':
@@ -825,7 +831,7 @@
     if (!to_stdout)
       {
 	sigset_t oldset;
-	int unlink_errno;
+	int unlink_errno = 0;
 
 	copy_stat (&istat);
 	if (close (ofd) != 0)
@@ -833,7 +839,8 @@
 
 	sigprocmask (SIG_BLOCK, &caught_signals, &oldset);
 	remove_ofname_fd = -1;
-	unlink_errno = xunlink (ifname) == 0 ? 0 : errno;
+	if (remove_ifname)
+	  unlink_errno = xunlink (ifname) == 0 ? 0 : errno;
 	sigprocmask (SIG_SETMASK, &oldset, NULL);
 
 	if (unlink_errno)


