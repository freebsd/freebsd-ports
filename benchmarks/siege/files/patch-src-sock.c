--- src/sock.c.ORIG	Sun Aug 29 13:39:37 2004
+++ src/sock.c	Sun Aug 29 13:38:01 2004
@@ -132,7 +132,7 @@
   if((gethostbyname_r( hn, &hent, hbf, sizeof(hbf), &hp, &herrno ) < 0)){
     hp = NULL;
   }
-#elif defined(sun)
+#elif defined(sun) || defined(__FreeBSD__)
 # ifdef HAVE_GETIPNODEBYNAME
   hp = getipnodebyname( hn, AF_INET, 0, &herrno );
 # else /* default use gethostbyname_r*/

