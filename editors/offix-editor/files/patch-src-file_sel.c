--- src/file_sel.c.orig	Sun Sep 29 02:36:26 2002
+++ src/file_sel.c	Sun Sep 29 02:36:40 2002
@@ -86,10 +86,12 @@
 #include <stdlib.h>
 #include <unistd.h>
 
+#ifndef __FreeBSD__
 extern char *malloc();
 extern char *realloc();
 extern char *getenv();                    /* Lesen der Umgebungsvariablen */
 extern int chdir();                       /* Directorywechsel */
+#endif
 static char *filename;                    /* Pointer auf Filename */
 static Widget file_s;                     /* Popupshell fuer Fileselectbox */
 static Widget list_direct,                /* Directoryeintraege im Fenster */
