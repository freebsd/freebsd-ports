--- src/gauche/arith_i386.h.orig       Sun Sep 22 19:48:19 2002
+++ src/gauche/arith_i386.h    Sun Sep 22 19:49:05 2002
@@ -23,6 +23,8 @@
  *  r <- x + y + c  mod wordsize
  *  c <- 1 if carry, 0 otherwise
  */
+/* bad register voodoo... let the 'portable' version catch this.
+      fails on both 4.2-release and 5.0-current
 
 #define UADD(r, c, x, y) \
     asm("shrl $1, %2;" \
@@ -32,7 +34,7 @@
         "rcll $1, %1;" \
            :"=&r" (r), "=&r" (c) \
            :"1" (c), "g"(x), "g"(y))
-
+*/
 /*-----------------------------------------------------------------
  * UADDOV(r, v, x, y)    unsigned word add with overflow check
  *  u_long : r, v, x, y;
