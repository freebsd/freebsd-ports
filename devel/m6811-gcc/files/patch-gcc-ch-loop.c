--- gcc/ch/loop.c.orig	Mon Jan 11 14:17:29 1999
+++ gcc/ch/loop.c	Mon Aug 25 18:56:36 2003
@@ -318,8 +318,8 @@
 (associated with all iterators).
 
  NOTE: Z.200, section 10.1 says that a block is ...
-       "the actions statement list in a do action, including any
-       loop counter and while control".  This means that an exp-
+       ;the actions statement list in a do action, including any
+       loop counter and while control;.  This means that an exp-
        ression in a WHILE control can include references to the
        loop counters created for the loop''s exclusive use.  
        Example:
