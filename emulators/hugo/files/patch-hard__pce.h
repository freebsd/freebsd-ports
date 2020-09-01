--- hard_pce.h.orig	2004-05-26 20:54:15 UTC
+++ hard_pce.h
@@ -64,8 +64,8 @@ void	IO_write (UInt16 A,UChar V);
 UChar	IO_read  (UInt16 A);
 void	bank_set (UChar P, UChar V);
 
-void	(*write_memory_function)(UInt16,UChar);
-UChar	(*read_memory_function)(UInt16);
+extern void	(*write_memory_function)(UInt16,UChar);
+extern UChar	(*read_memory_function)(UInt16);
 
 #define Wr6502(A,V) ((*write_memory_function)((A),(V)))
 
