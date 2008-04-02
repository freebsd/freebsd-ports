--- unzip-5.52.orig/fileio.c
+++ fileio.c
@@ -413,7 +413,11 @@
 #endif /* NOVELL_BUG_FAILSAFE */
     Trace((stderr, "open_outfile:  doing fopen(%s) for writing\n",
       FnFilter1(G.filename)));
+#if defined(SYMLINKS) || defined(QLZIP)
+    if ((G.outfile = fopen(G.filename, FOPWR)) == (FILE *)NULL) {
+#else
     if ((G.outfile = fopen(G.filename, FOPW)) == (FILE *)NULL) {
+#endif
         Info(slide, 0x401, ((char *)slide, LoadFarString(CannotCreateFile),
           FnFilter1(G.filename)));
         return 1;
