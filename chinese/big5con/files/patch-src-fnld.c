--- src/fnld.c.orig	Mon May 16 14:04:51 2005
+++ src/fnld.c	Mon May 16 14:04:51 2005
@@ -21,7 +21,7 @@
 
 struct fontRegs *dbFReg, *sbFReg;
 
-u_char         *GetShmem();
+u_char         *GetShmem(char);
 
 void 
 FontDetach(bool down)
