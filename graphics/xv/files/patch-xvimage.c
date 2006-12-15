--- xvimage.c.orig	Fri Dec 15 07:32:23 2006
+++ xvimage.c	Fri Dec 15 07:45:46 2006
@@ -1977,10 +1977,10 @@
   case 12:
   case 15:
   case 16: {
-    unsigned short  *imagedata, *ip;
+    byte  *imagedata, *ip;
     byte  *pp;
 
-    imagedata = (unsigned short *) malloc((size_t) (2*wide*high));
+    imagedata = (byte *) malloc((size_t) (2*wide*high));
     if (!imagedata) FatalError("couldn't malloc imagedata");
 
     xim = XCreateImage(theDisp,theVisual,dispDEEP,ZPixmap,0,
@@ -2003,8 +2003,8 @@
 	if (dithpic) xcol = ((*pp) ? white : black) & 0xffff;
 		else xcol = xcolors[*pp] & 0xffff;
 
-	*((unsigned char *)ip)++ = (xcol>>8) & 0xff;
-	*((unsigned char *)ip)++ = (xcol) & 0xff;
+	*(ip++) = (xcol>>8) & 0xff;
+	*(ip++) = (xcol) & 0xff;
       }
     }
     else {   /* LSBFirst */
@@ -2014,8 +2014,8 @@
 	if (dithpic) xcol = ((*pp) ? white : black) & 0xffff;
 	        else xcol = xcolors[*pp];
 
-	*((unsigned char *)ip)++ = (xcol) & 0xff;
-	*((unsigned char *)ip)++ = (xcol>>8) & 0xff;
+	*(ip++) = (xcol) & 0xff;
+	*(ip++) = (xcol>>8) & 0xff;
       }
     }
   }
@@ -2214,7 +2214,8 @@
 		*ip++ = xcol & 0xff;
 		break;
 	      case 16:
-		*((CARD16 *)ip)++ = (CARD16)xcol;
+		*((CARD16 *)ip) = (CARD16)xcol;
+		ip += 2;
 		break;
 	      }
 	    }
@@ -2243,7 +2244,8 @@
 	  *ip++ = xcol & 0xff;
 	  break;
 	case 16:
-	  *((CARD16 *)ip)++ = (CARD16)xcol;
+	  *((CARD16 *)ip) = (CARD16)xcol;
+	  ip += 2;
 	  break;
 	case 24:
 	  *ip++ = (xcol >> 16) & 0xff;
@@ -2251,7 +2253,8 @@
 	  *ip++ =  xcol        & 0xff;
 	  break;
 	case 32:
-	  *((CARD32 *)ip)++ = (CARD32)xcol;
+	  *((CARD32 *)ip) = (CARD32)xcol;
+	  ip += 4;
 	  break;
 	}
       }
