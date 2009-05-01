--- src/mkvmi.c.orig	2009-01-23 13:50:02.000000000 -0500
+++ src/mkvmi.c	2009-04-30 16:30:34.948715970 -0400
@@ -31,6 +31,9 @@
 #else
 #include <unistd.h>
 #endif
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#endif
 
 /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 This program creates pl-codetable.c, pl-jumptable.ic   and pl-vmi.h from
@@ -97,7 +100,7 @@
   return NULL;
 }
 
-
+#if (__FreeBSD_version >= 800000 && __FreeBSD_version <= 800057) || __FreeBSD_version < 701101
 static char *
 strndup(const char *in, size_t len)
 { char *s = malloc(len+1);
@@ -107,6 +110,7 @@
 
   return s;
 }
+#endif
 
 
 static int
