
$FreeBSD$

--- src/bitwise.c.orig	Mon Nov 10 14:06:08 2003
+++ src/bitwise.c	Sun Dec  7 02:36:26 2003
@@ -251,7 +251,8 @@
 /* Read in bits without advancing the bitptr; bits <= 32 */
 long oggpackB_look(oggpack_buffer *b,int bits){
   unsigned long ret;
-  int m=32-bits;
+  unsigned long m=mask[bits];
+  int s=32-bits;
 
   bits+=b->endbit;
 
@@ -272,7 +273,7 @@
       }
     }
   }
-  return (ret>>(m>>1))>>((m+1)>>1);
+  return ((ret>>(s>>1))>>((s+1)>>1)&m);
 }
 
 long oggpack_look1(oggpack_buffer *b){
@@ -347,7 +348,8 @@
 /* bits <= 32 */
 long oggpackB_read(oggpack_buffer *b,int bits){
   unsigned long ret;
-  long m=32-bits;
+  unsigned long m=mask[bits];
+  long s=32-bits;
   
   bits+=b->endbit;
 
@@ -369,7 +371,7 @@
       }
     }
   }
-  ret=(ret>>(m>>1))>>((m+1)>>1);
+  ret=((ret>>(s>>1))>>((s+1)>>1)&m);
   
  overflow:
 
