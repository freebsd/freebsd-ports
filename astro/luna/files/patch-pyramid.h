--- pyramid.h.orig	2016-07-26 13:07:24 UTC
+++ pyramid.h
@@ -14,13 +14,16 @@
 # include	<dos.h>
 # include	<stdlib.h>
 # include	<string.h>
-# define	LASCTIME	(30)
+# define	LASCTIME	(26)
 
 #else	/* UNIX */
-# include	<sys/time.h>
+/*# include	<sys/time.h>*/
+# include	<time.h>
   typedef time_t	Time_t;
 # include	<memory.h>  
-# define	LASCTIME	(30)
+# define	LASCTIME	(26)
+  extern char	*asctime();
+  extern char	*getenv();
 #endif	/* MSDOS or not */
  
 typedef long	ABDATE;
@@ -52,15 +55,6 @@ typedef long	ABDATE;
 # if defined(MSDOS)
 	extern char		*Asctime(struct tm *tmp);	
 	extern char		*capitalize(char *chp);
-#	define	Tolower(cc)	tolower(cc)
-#	define	Toupper(cc)	toupper(cc)
-# else	/* MSDOS */
-#	define	Asctime	asctime	
-/*#	define	Tolower(cc)	\
-/*		(('A' <= (cc) && (cc) <= 'Z') ? ((cc) - 'A' + 'a') : (cc))
-/*#	define	Toupper(cc)	\
-/*		(('a' <= (cc) && (cc) <= 'z') ? ((cc) - 'a' + 'A') : (cc))
- */
 # endif		/* ANSI and MSDOS */	
 
 #else	/* ANSI */
@@ -69,3 +63,16 @@ typedef long	ABDATE;
  	extern void		tzconv();
  	extern void		tomorrow();
 #endif	/* ANSI or not */
+
+
+#if defined(MSDOS)
+# define	Tolower(cc)	tolower(cc)
+# define	Toupper(cc)	toupper(cc)
+
+#else
+# define	Asctime	asctime
+# define	Tolower(cc)	\
+		(('A' <= (cc) && (cc) <= 'Z') ? ((cc) - 'A' + 'a') : (cc))
+# define	Toupper(cc)	\
+		(('a' <= (cc) && (cc) <= 'z') ? ((cc) - 'a' + 'A') : (cc))
+#endif	/* MSDOS */
