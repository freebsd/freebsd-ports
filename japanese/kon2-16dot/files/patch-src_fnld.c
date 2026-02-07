--- src/fnld.c.orig	1997-01-24 09:36:30.000000000 +0900
+++ src/fnld.c	2012-05-10 00:14:28.847552685 +0900
@@ -42,7 +42,7 @@
 
 struct fontRegs *dbFReg, *sbFReg;
 
-u_char	*GetShmem();
+u_char	*GetShmem(char);
 
 void FontDetach(bool down)
 {
