--- bios.c.orig	Mon Nov 15 06:33:54 1999
+++ bios.c	Mon Nov 15 06:39:55 1999
@@ -227,7 +227,7 @@
 	case BIOS:      /* System Reset (coldboot) */
 	case DIRBUF-20:
 	    if (!silent_exit)
-		printf("\nCp/M BIOS COLDBOOT takes you back to Linux\n");
+		printf("\nCp/M BIOS COLDBOOT takes you back to FreeBSD\n");
 	    exit(0);
 	case BIOS+3:    /* System Reset (warmboot) */
 	case DIRBUF-19:
