
$FreeBSD$

--- gdk-pixbuf/pixops/have_mmx.S	2001/11/16 10:34:50	1.1
+++ gdk-pixbuf/pixops/have_mmx.S	2001/11/16 10:35:21
@@ -19,6 +19,8 @@
 	popfl
 	pushfl
 	popl	%eax
+	pushl	%ebx
+	popfl
 
 	cmpl	%eax, %ebx
 
