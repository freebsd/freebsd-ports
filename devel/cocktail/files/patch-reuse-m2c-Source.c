--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Source.c	Tue Feb 15 14:27:01 1994
+++ ./reuse/m2c/Source.c	Thu Aug  5 18:49:34 2004
@@ -45,9 +45,6 @@
 CARDINAL Size;
 # endif
 {
-  INTEGER n;
-  struct S_1 *BufferPtr;
-
   return rRead(File, Buffer, (LONGINT)Size);
 }
 
