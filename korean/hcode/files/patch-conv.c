--- conv.c.orig	1998-03-11 04:46:36.000000000 -0500
+++ conv.c	2013-06-12 19:31:05.000000000 -0400
@@ -27,7 +27,7 @@
 		ju = VOW[((wc>>8)&0xff)-0xa1][1];
 		jo = CON[(wc&0xff)-0xa1][2];
 		if ( ch<0x8000||ju<0x8000||jo<0x8000 )
-			fprintf(stderr,"%x is not valid in Trigem Code\n",wc);
+			fprintf(stderr,"%lx is not valid in Trigem Code\n",wc);
 		return (ch&0xfc00)+(ju&0x03e0)+(jo&0x1f);
 	}
 
@@ -78,6 +78,7 @@
 	if ( wc>>16 == 0x8ffb ) 				/* KS */
 		return wc ;
 
+	h3 = 0;
 	if ( wc>>16 == 0 ) {					/* TR */
 		tr = wc;
 	} else {
@@ -104,6 +105,7 @@
 {
 	int ch,ju,jo;
 
+	ch = ju = jo = 0;
 	if ( wc>>16 == 0 ) {    /* Trigem */
 		for (ch=NoCON-1; ch>0; ch--)
 			if (CON[ch][1]==(wc&0x7c00)+0x8041) break;
