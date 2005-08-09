Index: src/ftp.c
===================================================================
--- src/ftp.c	(revision 2038)
+++ src/ftp.c	(working copy)
@@ -1023,7 +1023,6 @@
   err = ftp_response (csock, &respline);
   if (err != FTPOK)
     {
-      xfree (respline);
       /* The control connection is decidedly closed.  Print the time
 	 only if it hasn't already been printed.  */
       if (res != -1)
