--- font/minix.c.orig	1997-01-24 19:09:59.000000000 +0900
+++ font/minix.c	2012-05-10 00:17:11.703557005 +0900
@@ -62,7 +62,7 @@
     unsigned short end_code;
     char _unused[502];	/* empty */
     char memo[FH_MEMO_SIZE];
-    long sum;
+    int sum;
 };
 
 #define FONT_HEAD_SIZE		sizeof(struct font_header)
