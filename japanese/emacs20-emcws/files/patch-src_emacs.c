
$FreeBSD: /tmp/pcvs/ports/japanese/emacs20-emcws/files/Attic/patch-src_emacs.c,v 1.1 2002-10-30 13:30:28 taoka Exp $

--- src/emacs.c.orig	Wed May 24 15:58:54 2000
+++ src/emacs.c	Mon Jul 29 23:23:20 2002
@@ -602,7 +602,6 @@
   char stack_bottom_variable;
   int skip_args = 0;
   extern int errno;
-  extern int sys_nerr;
 #ifdef HAVE_SETRLIMIT
   struct rlimit rlim;
 #endif
