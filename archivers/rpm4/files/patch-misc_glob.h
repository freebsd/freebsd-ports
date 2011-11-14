--- misc/glob.h.orig	2011-11-14 22:06:03.000000000 +0100
+++ misc/glob.h	2011-11-14 22:07:01.000000000 +0100
@@ -110,10 +110,11 @@
 #endif
 typedef struct
   {
-    __size_t gl_pathc;		/* Count of paths matched by the pattern.  */
-    char **gl_pathv;		/* List of matched pathnames.  */
-    __size_t gl_offs;		/* Slots to reserve in `gl_pathv'.  */
-    int gl_flags;		/* Set to FLAGS, maybe | GLOB_MAGCHAR.  */
+    __size_t gl_pathc;		/* Count of total paths so far. */
+    __size_t gl_matchc;	/* Count of paths matching pattern. */
+    __size_t gl_offs;		/* Reserved at beginning of gl_pathv. */
+    int gl_flags;		/* Copy of flags parameter to glob. */
+    char **gl_pathv;		/* List of paths matching pattern. */
 
     /* If the GLOB_ALTDIRFUNC flag is set, the following functions
	are used instead of the normal file access functions.  */
