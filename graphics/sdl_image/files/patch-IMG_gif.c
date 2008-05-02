--- IMG_gif.c	2007/02/13 10:09:17	2970
+++ IMG_gif.c	2007/12/28 16:43:56	3462
@@ -418,6 +418,10 @@
     static int stack[(1 << (MAX_LWZ_BITS)) * 2], *sp;
     register int i;
 
+    /* Fixed buffer overflow found by Michael Skladnikiewicz */
+    if (input_code_size > MAX_LWZ_BITS)
+        return -1;
+
     if (flag) {
 	set_code_size = input_code_size;
 	code_size = set_code_size + 1;
