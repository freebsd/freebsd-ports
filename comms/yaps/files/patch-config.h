--- config.h.orig	1997-06-14 10:32:19 UTC
+++ config.h
@@ -26,24 +26,24 @@
  * Needed only by some systems, which do not define FD_SET etc.
  * in sys/time.h
  */
-# define	HAVE_SYS_SELECT_H	0
+# define	HAVE_SYS_SELECT_H	1
 
 /*
  * If you have locales set this. This is useful to for character
  * conversion/classification
  */
-# define	HAVE_LOCALE_H		0
+# define	HAVE_LOCALE_H		1
 
 /*
  * If you have Posix regular expressions, set this. Otherwise a
  * very weak replacement is used to find matching services
  */
-# define	HAVE_REGEX_H		0
+# define	HAVE_REGEX_H		1
 
 /*
  * one of these is required for SysV like lockfiles
  */
-# define	HAVE_SYS_SYSMACROS_H	1
+# define	HAVE_SYS_SYSMACROS_H	0
 # define	HAVE_SYS_MKDEV_H	0
 
 /*
@@ -61,19 +61,19 @@
  * If the library contains this function, a call to it is required
  * to get valid return values from localtime
  */
-# define	HAVE_TZSET		0
+# define	HAVE_TZSET		1
 
 /*
  * If these are not set, chmod()/chown() are used
  */
-# define	HAVE_FCHMOD		0
-# define	HAVE_FCHOWN		0
+# define	HAVE_FCHMOD		1
+# define	HAVE_FCHOWN		1
 
 /*
  * If you have sigsetjmp() you definitly want to set this, otherwise 
  * longjmp() from the signal handler leads into chaos
  */
-# define	HAVE_SIGSETJMP		0
+# define	HAVE_SIGSETJMP		1
 
 /*
  * Memory access functions. Nearly everybody has memcpy()/memset(), so
@@ -105,7 +105,7 @@
  * If your realloc(3) function cannot handle realloc (NULL, size), then
  * set this to 1, otherwise to 0
  */
-# define	BROKEN_REALLOC		1
+# define	BROKEN_REALLOC		0
 
 /*      -------------- END OF CHANGEABLE PART ------------------	*/
 /*}}}*/
