--- src/irsim/rsim.c.orig	Sun Oct  8 13:23:58 2006
+++ src/irsim/rsim.c	Sun Oct  8 13:24:44 2006
@@ -130,6 +130,8 @@
 
 private	char	not_in_stop[] = "Can't do that while stoped, try \"C\"\n";
 
+private int clockit();
+private int undefseq();
 
 /* 
  * Parse line into tokens, filling up targv and WildCard, and setting 'targc'
@@ -1299,7 +1301,7 @@
 
 
 /* assert a bit vector */
-private int doAssert()
+int doAssert()
   {
     char      *mask, *value, *name;
     Find1Arg  f;
