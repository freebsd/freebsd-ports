--- cmp3listfiles.c.orig	Fri Jul 18 17:55:33 2003
+++ cmp3listfiles.c	Fri Jul 18 17:56:23 2003
@@ -270,13 +270,13 @@
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
