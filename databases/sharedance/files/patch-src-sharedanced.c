--- src/sharedanced.c.orig	2008-04-15 00:45:17.000000000 +0800
+++ src/sharedanced.c	2008-04-15 00:45:25.000000000 +0800
@@ -99,27 +99,6 @@
 #endif
 }
 
-static void setprogname(const char * const title)
-{
-#ifndef NO_PROCNAME_CHANGE
-# ifdef HAVE_SETPROCTITLE
-    setproctitle("-%s", title);
-# elif defined(__linux__)
-    if (argv0 != NULL) {
-        memset(argv0[0], 0, argv_lth);
-        strncpy(argv0[0], title, argv_lth - 2);
-        argv0[1] = NULL;
-    }
-# elif defined(__hpux__)
-    union pstun pst;
-
-    pst.pst_command = title;
-    pstat(PSTAT_SETCMD, pst, strlen(title), 0, 0);
-# endif
-#endif
-    (void) title;
-}
-
 static void usage(void)
 {
     puts("\n" PACKAGE_STRING " - " __DATE__ "\n");
