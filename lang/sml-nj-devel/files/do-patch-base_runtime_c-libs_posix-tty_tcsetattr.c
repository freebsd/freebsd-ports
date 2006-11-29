--- base/runtime/c-libs/posix-tty/tcsetattr.c.orig	Thu Jun  1 20:34:03 2000
+++ base/runtime/c-libs/posix-tty/tcsetattr.c	Sun Nov 19 13:36:18 2006
@@ -30,7 +30,7 @@
     data.c_oflag = REC_SELWORD(termio_rep, 1);
     data.c_cflag = REC_SELWORD(termio_rep, 2);
     data.c_lflag = REC_SELWORD(termio_rep, 3);
-    memcpy (data.c_cc, REC_SELPTR(void, termio_rep, 4), NCCS);
+    memcpy (data.c_cc, GET_SEQ_DATAPTR(void, REC_SEL(termio_rep, 4)), NCCS);
     sts = cfsetispeed (&data, REC_SELWORD(termio_rep, 5));
     if (sts < 0)
 	return RAISE_SYSERR(msp, sts);
