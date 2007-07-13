--- async/suio_vuprintf.C.orig	2005-11-01 16:20:33.000000000 +0000
+++ async/suio_vuprintf.C	2007-07-12 22:38:56.000000000 +0000
@@ -139,7 +139,7 @@
   int dprec;			/* a copy of prec if [diouxX], 0 otherwise */
   int realsz;			/* field size expanded by dprec */
   int size;			/* size of converted field or string */
-  char *xdigs = "";		/* digits for [xX] conversion */
+  char *xdigs = (char *)"";	/* digits for [xX] conversion */
 
   char buf[BUF];                /* space for %c, %[diouxX], %[eEfgG] */
   char ox[2];                   /* space for 0x hex-prefix */
@@ -392,7 +392,7 @@
       /* NOSTRICT */
       _uquad = (u_long) va_arg (ap, void *);
       base = HEX;
-      xdigs = "0123456789abcdef";
+      xdigs = (char *)"0123456789abcdef";
       flags |= HEXPREFIX;
       ch = 'x';
       goto nosign;
@@ -435,10 +435,10 @@
       base = DEC;
       goto nosign;
     case 'X':
-      xdigs = "0123456789ABCDEF";
+      xdigs = (char *)"0123456789ABCDEF";
       goto hex;
     case 'x':
-      xdigs = "0123456789abcdef";
+      xdigs = (char *)"0123456789abcdef";
     hex:
       _uquad = UARG ();
       base = HEX;
@@ -498,7 +498,7 @@
 	  break;
 
 	default:
-	  cp = "bug in vfprintf: bad base";
+	  cp = (char *)"bug in vfprintf: bad base";
 	  size = strlen (cp);
 	  goto skipsize;
 	}
