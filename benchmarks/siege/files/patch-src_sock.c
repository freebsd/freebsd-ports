--- src/sock.c.orig	2016-05-20 11:41:06 UTC
+++ src/sock.c
@@ -149,7 +149,7 @@ new_socket(CONN *C, const char *hostpara
       hp = NULL;
     }
   }
-#elif defined(sun)
+#elif defined(sun) || defined(__FreeBSD__)
 # ifdef HAVE_GETIPNODEBYNAME
   hp = getipnodebyname(hn, AF_INET, 0, &herrno);
 # else /* default use gethostbyname_r*/
@@ -191,7 +191,7 @@ new_socket(CONN *C, const char *hostpara
 
   memset((void*) &cli, 0, sizeof(cli));
   memcpy(&cli.sin_addr, hp->h_addr, hp->h_length);
-#if defined(sun)
+#if defined(sun) || defined(__FreeBSD__)
 # ifdef  HAVE_FREEHOSTENT
   freehostent(hp);
 # endif/*HAVE_FREEHOSTENT*/ 
