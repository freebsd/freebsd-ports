--- buffer.c.orig	Tue Apr 13 14:08:08 1999
+++ buffer.c	Fri Apr 21 20:17:12 2006
@@ -41,7 +41,8 @@
 void buffer_end(void)
 {
 #ifndef NOXFERMEM
-	xfermem_putcmd(buffermem->fd[XF_WRITER], XF_CMD_TERMINATE);
+	if (buffermem)
+		xfermem_putcmd(buffermem->fd[XF_WRITER], XF_CMD_TERMINATE);
 #endif
 }
 
