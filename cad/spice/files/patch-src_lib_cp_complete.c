--- src/lib/cp/complete.c.orig	1991-06-19 03:55:38 UTC
+++ src/lib/cp/complete.c
@@ -445,14 +445,14 @@ cp_ccon(on)
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
