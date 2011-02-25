--- ./src/mesa/x86-64/xform4.S.orig	2009-01-22 18:38:35.000000000 +0100
+++ ./src/mesa/x86-64/xform4.S	2011-01-28 18:09:55.000000000 +0100
@@ -53,7 +53,7 @@ _mesa_x86_64_transform_points4_general:
  *	rdx = source
  */
 	movl V4F_COUNT(%rdx), %ecx	/* count */
-	movzx V4F_STRIDE(%rdx), %eax	/* stride */
+	movzbl V4F_STRIDE(%rdx), %eax	/* stride */
 
 	movl %ecx, V4F_COUNT(%rdi)	/* set dest count */
 	movl $4, V4F_SIZE(%rdi)		/* set dest size */
@@ -135,7 +135,7 @@ _mesa_x86_64_transform_points4_3d:
 	movaps 16(%rax), %xmm10
 
 	movl V4F_COUNT(%rdx), %ecx	/* count */
-	movzx V4F_STRIDE(%rdx), %eax	/* stride */
+	movzbl V4F_STRIDE(%rdx), %eax	/* stride */
 
 	movl %ecx, V4F_COUNT(%rdi)	/* set dest count */
 	movl $4, V4F_SIZE(%rdi)		/* set dest size */
@@ -195,7 +195,7 @@ p4_3d_done:
 _mesa_x86_64_transform_points4_identity:
 
 	movl V4F_COUNT(%rdx), %ecx	/* count */
-	movzx V4F_STRIDE(%rdx), %eax	/* stride */
+	movzbl V4F_STRIDE(%rdx), %eax	/* stride */
 
 	movl %ecx, V4F_COUNT(%rdi)	/* set dest count */
 	movl $4, V4F_SIZE(%rdi)		/* set dest size */
@@ -223,7 +223,7 @@ p4_identity_done:
 _mesa_3dnow_transform_points4_3d_no_rot:
 
 	movl V4F_COUNT(%rdx), %ecx	/* count */
-	movzx V4F_STRIDE(%rdx), %eax	/* stride */
+	movzbl V4F_STRIDE(%rdx), %eax	/* stride */
 
 	movl %ecx, V4F_COUNT(%rdi)	/* set dest count */
 	movl $4, V4F_SIZE(%rdi)		/* set dest size */
@@ -287,7 +287,7 @@ p4_3d_no_rot_done:
 _mesa_3dnow_transform_points4_perspective:
 
 	movl V4F_COUNT(%rdx), %ecx	/* count */
-	movzx V4F_STRIDE(%rdx), %eax	/* stride */
+	movzbl V4F_STRIDE(%rdx), %eax	/* stride */
 
 	movl %ecx, V4F_COUNT(%rdi)	/* set dest count */
 	movl $4, V4F_SIZE(%rdi)		/* set dest size */
@@ -353,7 +353,7 @@ p4_perspective_done:
 _mesa_3dnow_transform_points4_2d_no_rot:
 
 	movl V4F_COUNT(%rdx), %ecx	/* count */
-	movzx V4F_STRIDE(%rdx), %eax	/* stride */
+	movzbl V4F_STRIDE(%rdx), %eax	/* stride */
 
 	movl %ecx, V4F_COUNT(%rdi)	/* set dest count */
 	movl $4, V4F_SIZE(%rdi)		/* set dest size */
@@ -408,7 +408,7 @@ p4_2d_no_rot_done:
 _mesa_3dnow_transform_points4_2d:
 
 	movl V4F_COUNT(%rdx), %ecx	/* count */
-	movzx V4F_STRIDE(%rdx), %eax	/* stride */
+	movzbl V4F_STRIDE(%rdx), %eax	/* stride */
 
 	movl %ecx, V4F_COUNT(%rdi)	/* set dest count */
 	movl $4, V4F_SIZE(%rdi)		/* set dest size */
