Index: src/progress.c
===================================================================
RCS file: /pack/anoncvs/wget/src/progress.c,v
retrieving revision 1.21
retrieving revision 1.22
diff -u -r1.21 -r1.22
--- src/progress.c	2001/12/09 01:24:40	1.21 WGET_1_8
+++ src/progress.c	2001/12/09 04:51:40	1.22
@@ -647,7 +647,7 @@
 	/* Hours not printed: pad with three spaces (two digits and
 	   colon). */
 	APPEND_LITERAL ("   ");
-      else if (eta_hrs >= 10)
+      else if (eta_hrs < 10)
 	/* Hours printed with one digit: pad with one space. */
 	*p++ = ' ';
       else
