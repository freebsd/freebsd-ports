--- src/sock.c.orig	2010-05-17 15:57:59.000000000 +0200
+++ src/sock.c	2012-05-25 15:55:21.743780806 +0200
@@ -126,7 +126,7 @@
       hp = NULL;
     }
   }
-#elif defined(sun)
+#elif defined(sun) || defined(__FreeBSD__)
 # ifdef HAVE_GETIPNODEBYNAME
   hp = getipnodebyname(hn, AF_INET, 0, &herrno);
 # else /* default use gethostbyname_r*/
@@ -154,7 +154,7 @@
   if(hp == NULL){ return -1; } 
   memset((void*) &cli, 0, sizeof(cli));
   memcpy(&cli.sin_addr, hp->h_addr, hp->h_length);
-#if defined(sun)
+#if defined(sun) || defined(__FreeBSD__)
 # ifdef  HAVE_FREEHOSTENT
   freehostent(hp);
 # endif/*HAVE_FREEHOSTENT*/ 
