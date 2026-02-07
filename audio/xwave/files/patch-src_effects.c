--- src/effects.c.orig	1998-11-08 23:22:55 UTC
+++ src/effects.c
@@ -348,7 +348,7 @@ void props_return(Sample_Return *sr)
 	
 	switch (sr->res) {
 	 case 8: {
-#if defined (linux) || defined (FreeBSD) 
+#if defined (linux) || defined (__FreeBSD__) 
 	     for (i=0;i<newlength;i++) newbuf[i]=obuf[(i<<1)+1]+128;
 #elif defined (sgi) || defined (sun)
 	     for (i=0;i<newlength;i++) newbuf[i]=obuf[(i<<1)]+128;
@@ -356,7 +356,7 @@ void props_return(Sample_Return *sr)
 	     break;
 	 }
 	 case 16: {
-#if defined (linux) || defined (FreeBSD) 
+#if defined (linux) || defined (__FreeBSD__) 
 	     for (i=0;i<wd->length;i++) newbuf[(i<<1)+1]=obuf[i]-128;
 #elif defined (sgi) || defined (sun)
 	     for (i=0;i<wd->length;i++) newbuf[(i<<1)]=obuf[i]-128;
