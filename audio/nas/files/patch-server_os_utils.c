$FreeBSD$

 utils.c:124: conflicting types for `sbrk'
 /usr/include/unistd.h:212: previous declaration of `sbrk'

--- server/os/utils.c.orig	Sat May 25 10:07:51 2002
+++ server/os/utils.c	Sat May 25 10:21:48 2002
@@ -120,7 +120,7 @@ static mutex print_lock
 
 void ddxUseMsg(void);
 
-#if !defined(SVR4) && !defined(hpux) && !defined(linux) && !defined(AMOEBA) && !defined(_MINIX)
+#if !defined(SVR4) && !defined(hpux) && !defined(linux) && !defined(AMOEBA) && !defined(_MINIX) && !defined(__FreeBSD__)
 extern char *sbrk();
 #endif
 
