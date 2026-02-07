--- xjdic.h.orig	Thu Sep  3 02:05:28 1998
+++ xjdic.h	Wed Oct  7 11:55:52 1998
@@ -3,7 +3,7 @@
 #define NRKANA 250*2   /*  size of the romaji to kana tables*/
 #define NOFILT 10      /* maximum number of general filters */
 #define VMAX 350       /* maximum entries in the verb table */
-#define DEFAULT_DICDIR ""    /* could be: "/usr/local/lib/xjdic"   */
+#define DEFAULT_DICDIR "/usr/local/share/dict/edict"    /* could be: "/usr/local/lib/xjdic"   */
 #define NOHITS 1000       /* size of hittab  */
 #define SPTAG '@'         /* character that flags priority entries */
 #define KFBUFFSIZE 2000   /* size of the KFlush buffer */
