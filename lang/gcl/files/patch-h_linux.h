Index: h/linux.h
===================================================================
RCS file: /cvsroot/gcl/gcl/h/linux.h,v
retrieving revision 1.7.6.4
diff -u -d -b -B -r1.7.6.4 linux.h
--- h/linux.h	3 May 2004 21:35:58 -0000	1.7.6.4
+++ h/linux.h	19 Jul 2004 13:19:34 -0000
@@ -138,8 +138,6 @@
   sprintf(command, "ld -d -S -N -x -A %s -T %x %s %s -o %s", \
             main,start,input,ldarg,output)
 
-#define SET_SESSION_ID() (setpgrp() ? -1 : 0)
-
 #define CLEANUP_CODE \
   setbuf(stdin,0); \
    setbuf(stdout,0);
