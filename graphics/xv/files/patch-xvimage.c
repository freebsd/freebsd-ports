--- xvimage.c.orig	Sat Oct  7 21:38:26 2006
+++ xvimage.c	Sat Oct  7 21:44:00 2006
@@ -2003,8 +2003,8 @@
 	if (dithpic) xcol = ((*pp) ? white : black) & 0xffff;
 		else xcol = xcolors[*pp] & 0xffff;
 
-	*((unsigned char *)ip)++ = (xcol>>8) & 0xff;
-	*((unsigned char *)ip)++ = (xcol) & 0xff;
+	*(((unsigned char *)ip)++) = (xcol>>8) & 0xff;
+	*(((unsigned char *)ip)++) = (xcol) & 0xff;
       }
     }
     else {   /* LSBFirst */
@@ -2014,8 +2014,8 @@
 	if (dithpic) xcol = ((*pp) ? white : black) & 0xffff;
 	        else xcol = xcolors[*pp];
 
-	*((unsigned char *)ip)++ = (xcol) & 0xff;
-	*((unsigned char *)ip)++ = (xcol>>8) & 0xff;
+	*(((unsigned char *)ip)++) = (xcol) & 0xff;
+	*(((unsigned char *)ip)++) = (xcol>>8) & 0xff;
       }
     }
   }
