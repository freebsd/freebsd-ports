--- adventure/hdr.h.bak	Mon Nov 10 15:46:52 2003
+++ adventure/hdr.h	Wed Sep 29 03:30:55 2004
@@ -167,7 +167,7 @@
 void checkhints (void);
 void ciao (void);
 extern gid_t	egid;
-u_long crc (const char *ptr, size_t nr);
+u_long crc (const char *ptr, ssize_t nr);
 void crc_start (void);
 int dark (void);
 void datime (int *d, int *t);
