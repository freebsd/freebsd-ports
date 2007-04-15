--- spice/common/src/lib/cp/complete.c	Wed Jun 19 05:55:38 1991
+++ spice/common/src/lib/cp/complete.c	Sat Mar 17 11:51:56 2007
@@ -445,14 +445,14 @@
     ison = on;
 
     if (ison == true) {
-	(void) ioctl(fileno(cp_in), TERM_GET, (char *) &OS_Buf);
+    	tcgetattr(fileno(cp_in), &OS_Buf);
 	sbuf = OS_Buf;
 	sbuf.c_cc[VEOF] = 0;
 	sbuf.c_cc[VEOL] = ESCAPE;
 	sbuf.c_cc[VEOL2] = CNTRL_D;
-	(void) ioctl(fileno(cp_in), TERM_SET, (char *) &sbuf);
+    	tcsetattr(fileno(cp_in), TCSANOW, &OS_Buf);
     } else {
-	(void) ioctl(fileno(cp_in), TERM_SET, (char *) &OS_Buf);
+    	tcsetattr(fileno(cp_in), TCSANOW, &OS_Buf);
     }
 
 #  endif
