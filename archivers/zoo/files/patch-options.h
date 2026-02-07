--- options.h.orig	1993-05-01 04:27:59 UTC
+++ options.h
@@ -96,7 +96,6 @@ For documentation about this file, see o
 #define NIXTIME
 #define NIXFNAME
 #define NEEDCTYP
-#define NOENUM
 #define REN_STDC
 #define SETBUF
 #define GETTZ
@@ -110,6 +109,7 @@ For documentation about this file, see o
 #define ANSI_PROTO
 #define VOIDPTR		void *
 #else
+#define NOENUM
 #define NOSTRCHR /* not really needed for 4.3BSD */
 #define T_SIGNAL	int
 #define VARARGS
