From: Christian Spieler
Subject: zipnote.c: Close in_file instead of undefined file x
Bug-Debian: https://bugs.debian.org/628594
X-Debian-version: 3.0-4

--- zipnote.c.orig	2008-05-08 08:17:08 UTC
+++ zipnote.c
@@ -661,7 +661,7 @@ char **argv;            /* command line tokens */
     if ((r = zipcopy(z)) != ZE_OK)
       ziperr(r, "was copying an entry");
   }
-  fclose(x);
+  fclose(in_file);
 
   /* Write central directory and end of central directory with new comments */
   if ((c = zftello(y)) == (zoff_t)-1)    /* get start of central */
