--- src/effects.c.orig	Mon Nov  9 08:22:55 1998
+++ src/effects.c	Fri Jun 30 19:49:16 2000
@@ -348,7 +348,7 @@
 	
 	switch (sr->res) {
 	 case 8: {
-#if defined (linux) || defined (FreeBSD) 
+#if defined (linux) || defined (__FreeBSD__) 
 	     for (i=0;i<newlength;i++) newbuf[i]=obuf[(i<<1)+1]+128;
 #elif defined (sgi) || defined (sun)
 	     for (i=0;i<newlength;i++) newbuf[i]=obuf[(i<<1)]+128;
@@ -356,7 +356,7 @@
 	     break;
 	 }
 	 case 16: {
-#if defined (linux) || defined (FreeBSD) 
+#if defined (linux) || defined (__FreeBSD__) 
 	     for (i=0;i<wd->length;i++) newbuf[(i<<1)+1]=obuf[i]-128;
 #elif defined (sgi) || defined (sun)
 	     for (i=0;i<wd->length;i++) newbuf[(i<<1)]=obuf[i]-128;
