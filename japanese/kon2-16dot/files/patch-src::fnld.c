--- src/fnld.c.orig	Fri Jan 24 09:36:30 1997
+++ src/fnld.c	Sun Sep 19 04:10:25 2004
@@ -42,7 +42,7 @@
 
 struct fontRegs *dbFReg, *sbFReg;
 
-u_char	*GetShmem();
+u_char	*GetShmem(char);
 
 void FontDetach(bool down)
 {
