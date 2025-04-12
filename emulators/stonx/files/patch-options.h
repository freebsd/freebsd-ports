--- options.h.orig	2003-11-18 17:49:36 UTC
+++ options.h
@@ -87,6 +87,16 @@
 /* Set this to 1 for communication device for MiNT */
 #define MINT_COM 0
 
+/* Set this to 1 for unix pipes through GEMDOS AUX:/PRN: devices.
+ * Allows defining pipe commands with auxpipe/prnpipe keyword
+ * in stonxrc files. Mainly to allow TOS programs to print to
+ * the unix lp system. Eg Papyrus (option print through os)
+ * The corresponding patch allows quoted keyword arguments
+ * for any keyword and ~ path expansion.
+ * Also note, that enabling this option will slightly modify GEMDOS
+ * limits and behaviour! see gemdos.c/MAXDIRS/MAXFILES/H_OFFSET */
+#define LPPIPES 1
+
 /* Set this to 1, if you want Atari- to X-clipboard mapping and v.v. */
 #define CLIPBOARD 0 /* Does not work, will result in compiler errors */
 
