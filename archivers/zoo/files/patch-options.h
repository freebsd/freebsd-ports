--- ./options.h.orig	1993-05-01 06:27:59.000000000 +0200
+++ ./options.h	2011-12-22 14:00:55.000000000 +0100
@@ -96,7 +96,6 @@
 #define NIXTIME
 #define NIXFNAME
 #define NEEDCTYP
-#define NOENUM
 #define REN_STDC
 #define SETBUF
 #define GETTZ
@@ -110,6 +109,7 @@
 #define ANSI_PROTO
 #define VOIDPTR		void *
 #else
+#define NOENUM
 #define NOSTRCHR /* not really needed for 4.3BSD */
 #define T_SIGNAL	int
 #define VARARGS
