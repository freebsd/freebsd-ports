--- pal/unix/arch/i386/context.c.orig	Wed Jun 19 16:43:58 2002
+++ pal/unix/arch/i386/context.c	Tue Jul 30 00:24:36 2002
@@ -65,8 +65,9 @@
 
         if ((regFd = open(buf, O_RDONLY)) == -1) 
         {
-          ASSERT("open() failed %d (%s) \n", errno, strerror(errno));
-          return FALSE;
+	  bzero(registers, sizeof(struct reg));
+	  bRet = TRUE;
+	  goto EXIT;
         }
 
         if (lseek(regFd, 0, 0) == -1)
