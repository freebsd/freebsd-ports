--- src/em.c~	Tue Apr 16 15:06:51 2002
+++ src/em.c	Thu Jun 27 17:54:05 2002
@@ -362,7 +362,8 @@
   char *bufp;
   char *bufp2;
   int i = 0, j = 0,  nmea = 0;
-  int fd, nfds;
+  int fd;
+  extern int nfds;
 
   if (p[h->ndata] == em_checksum (p, h->ndata))
     {
@@ -475,7 +476,6 @@
     }
   if (nmea > 0)
     {
-      nfds = getdtablesize ();
       if (debug > 4)
 	fprintf (stderr, "%s", buf);
       for (fd = 0; fd < nfds; fd++)
