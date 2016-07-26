--- cmp3listfiles.c.orig	2001-06-13 20:13:16 UTC
+++ cmp3listfiles.c
@@ -270,13 +270,13 @@ void writelist(char *filepath)
 /*         XXX - alert person */
         return;
     fprintf(outfile,
-"##############################################################################
-# Dumped Cmp3 playlist ass file
-#
-# Addable features (on individual lines):
-# %%[command] - executes commands initially using system() call
-# @ - randomizes this playlist at load time
-# $ - turns on repeat mode at load time
+"##############################################################################\n\
+# Dumped Cmp3 playlist ass file\n\
+#\n\
+# Addable features (on individual lines):\n\
+# %%[command] - executes commands initially using system() call\n\
+# @ - randomizes this playlist at load time\n\
+# $ - turns on repeat mode at load time\n\
 #\n\n");
 
     filename = shmptr->plhead;
