--- src/pulsecore/proplist-util.c.orig	2008-07-26 17:01:44.000000000 -0400
+++ src/pulsecore/proplist-util.c	2008-07-26 17:02:32.000000000 -0400
@@ -37,7 +37,7 @@
 
 void pa_init_proplist(pa_proplist *p) {
     int a, b;
-#ifndef HAVE_DECL_ENVIRON
+#if HAVE_DECL_ENVIRON == 0
     extern char **environ;
 #endif
     char **e;
