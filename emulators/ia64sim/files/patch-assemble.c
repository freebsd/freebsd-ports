$NetBSD: patch-ac,v 1.1 1999/12/10 13:55:15 soren Exp $

--- asm/assemble.c.orig	Fri Dec 10 14:50:49 1999
+++ asm/assemble.c	Fri Dec 10 14:50:58 1999
@@ -280,7 +280,7 @@
             break;
 
          case 'i':                                   /* signed immediate */
-            imm = strtoll(inptr, &throwaway, 0);
+            imm = strtoq(inptr, &throwaway, 0);
             if( isdigit(refptr[3]) )
                maxbits = (refptr[2]-'0')*10 + (refptr[3]-'0');
             else
@@ -294,7 +294,7 @@
             break;
 
          case 'u':                                 /* unsigned immediate */
-            imm = strtoll(inptr, &throwaway, 0);
+            imm = strtoq(inptr, &throwaway, 0);
             maxbits = (refptr[2]-'0');
 	    if(maxbits==6)
 	       index = 65;	      /* <-- some ops need 1-64, not 0-63 */
