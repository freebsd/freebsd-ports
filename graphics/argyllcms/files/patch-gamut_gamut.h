--- gamut/gamut.h.orig	2020-08-19 11:32:00 UTC
+++ gamut/gamut.h
@@ -36,7 +36,7 @@
 #define MAXGAMN 10				/* Maximum gamut point neighbors returned */
 #define NSLOTS 6				/* Number of maximum direction slots */
 
-struct _vrml *wrl;				/* Declared in vrml.h, which may be #included after this */
+extern struct _vrml *wrl;			/* Declared in vrml.h, which may be #included after this */
 
 /* ------------------------------------ */
 #define NODE_STRUCT							\
