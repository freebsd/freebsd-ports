--- qt/md/axp.s.orig	Thu Sep 26 22:19:15 2002
+++ qt/md/axp.s	Thu Sep 26 22:30:31 2002
@@ -15,7 +15,7 @@
 
 	.text
 	.align 4
-	.file 2 "axp.s"
+	.file  "axp.s"
 
 	.globl qt_block
 	.globl qt_blocki
@@ -117,7 +117,7 @@
 	jsr $26,($27),0		# Call `cleanup'.
 
 	jsr $26,qt_error	# Cleanup erroniously returned.
-	.end qt_start
+	.end qt_vstart
 
 
 	#
