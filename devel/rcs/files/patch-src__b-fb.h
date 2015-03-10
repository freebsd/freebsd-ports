--- src/b-fb.h.orig	2013-04-20 20:08:38.000000000 +0200
+++ src/b-fb.h	2015-02-24 21:58:19.888149000 +0100
@@ -21,9 +21,9 @@
 */
 
 extern int change_mode (int fd, mode_t mode);
-extern void Ierror (void) exiting;
+exiting extern void Ierror (void);
 extern void testIerror (FILE *f);
-extern void Oerror (void) exiting;
+exiting extern void Oerror (void);
 extern void testOerror (FILE *o);
 extern FILE *fopen_safer (char const *filename, char const *type);
 extern void Ozclose (FILE **p);
