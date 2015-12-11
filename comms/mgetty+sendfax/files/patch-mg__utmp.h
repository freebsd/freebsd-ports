--- mg_utmp.h.orig	1997-01-12 14:53:42 UTC
+++ mg_utmp.h
@@ -1,4 +1,4 @@
-#ident "$Id: mg_utmp.h,v 4.1 1997/01/12 14:53:42 gert Exp $ Copyright (c) Gert Doering"
+static char sccs_mg_utmp[] = "$Id: mg_utmp.h,v 4.1 1997/01/12 14:53:42 gert Exp $ Copyright (c) Gert Doering";
 
 /* definitions for utmp reading / writing routines,
  * highly SysV / BSD dependent
@@ -31,6 +31,25 @@ void setutent();
 
 #else						 /* SunOS or generic BSD */
 
+#if defined(__FreeBSD__) && (__FreeBSD_version >= 900007)
+
+# include <utmpx.h>
+# define utmp		utmpx
+# define getutent	getutxent
+# define getutid	getutxid
+# define getutline	getutxline
+# define pututline	pututxline
+# define setutent	setutxent
+# define endutent	endutxent
+# define ut_time	ut_tv
+# define ut_name	ut_user
+       
+#define UT_INIT		INIT_PROCESS
+#define UT_LOGIN	LOGIN_PROCESS
+#define UT_USER		USER_PROCESS
+
+#else
+
 #include <sys/types.h>
 #include <utmp.h>
 
@@ -41,6 +60,8 @@ void setutent();
 #define UT_LOGIN	1
 #define UT_USER		2
 
+#endif						/* __FreeBSD_version */
+
 #endif						/* SysV vs. BSD */
 
 /* prototypes */
