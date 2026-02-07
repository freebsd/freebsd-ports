--- machine.h.orig	2002-05-27 15:00:00 UTC
+++ machine.h
@@ -841,9 +841,9 @@ typedef long	off_t;
 #endif
 #ifndef	TERMCAPLIB
 # ifdef	USETERMINFO
-# define	TERMCAPLIB		"-lcurses"
+# define	TERMCAPLIB		"-lncurses"
 # else
-# define	TERMCAPLIB		"-ltermlib"
+# define	TERMCAPLIB		"-lncurses"
 # endif
 #endif
 #ifndef	REGEXPLIB
