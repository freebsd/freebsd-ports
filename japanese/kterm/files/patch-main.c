--- main.c.orig	2024-02-02 17:45:34 UTC
+++ main.c
@@ -143,6 +143,10 @@ static Bool IsPts = False;
 #define WTMP
 #endif
 
+#if defined(__FreeBSD__)
+#define	USE_SYSV_UTMP
+#endif
+
 /* from xterm-200 */
 #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__INTERIX) || defined(__APPLE__)
 #ifndef USE_POSIX_TERMIOS
@@ -2374,7 +2378,7 @@ spawn ()
 #endif	/* sun */
 	struct passwd *pw = NULL;
 #ifdef UTMP
-#ifdef SVR4
+#if defined(SVR4) || (defined(__FreeBSD__) && __FreeBSD_version >= 900007)
 	struct utmpx utmp;
 #else
 	struct utmp utmp;
@@ -3286,7 +3290,7 @@ spawn ()
 
 		/* set up the new entry */
 		utmp.ut_type = USER_PROCESS;
-#ifndef linux
+#if !defined(linux) && !defined(__FreeBSD__)
 		utmp.ut_exit.e_exit = 2;
 #endif
 		(void) strncpy(utmp.ut_user,
@@ -3314,8 +3318,13 @@ spawn ()
 #endif
 		(void) strncpy(utmp.ut_host, buf, sizeof(utmp.ut_host));
 #endif
+#if defined(__FreeBSD__)
+		(void) strncpy(utmp.ut_user, pw->pw_name, 
+			       sizeof(utmp.ut_user));
+#else
 		(void) strncpy(utmp.ut_name, pw->pw_name, 
 			       sizeof(utmp.ut_name));
+#endif
 
 		utmp.ut_pid = getpid();
 #ifdef SVR4
@@ -3323,8 +3332,12 @@ spawn ()
 		utmp.ut_xtime = time ((Time_t *) 0);
 		utmp.ut_tv.tv_usec = 0;
 #else
+#if defined(__FreeBSD__)
+		utmp.ut_tv.tv_usec = 0;
+#else
 		utmp.ut_time = time ((Time_t *) 0);
 #endif
+#endif
 
 		/* write out the entry */
 		if (!resource.utmpInhibit)
@@ -3728,7 +3741,7 @@ Exit(n)
         int pty = term->screen.respond;  /* file descriptor of pty */
 #ifdef UTMP
 #ifdef USE_SYSV_UTMP
-#ifdef SVR4
+#if defined(SVR4) || (defined(__FreeBSD__) && __FreeBSD_version >= 900007)
 	struct utmpx utmp;
 	struct utmpx *utptr;
 #else
@@ -3774,7 +3787,11 @@ Exit(n)
 		    utmp.ut_xtime = time ((Time_t *) 0);
 		    utmp.ut_tv.tv_usec = 0;
 #else
+#if defined(__FreeBSD__)
+		    utmp.ut_tv.tv_usec = 0;
+#else
 		    utptr->ut_time = time((Time_t *) 0);
+#endif
 #endif
 		    (void) pututline(utptr);
 #ifdef WTMP
