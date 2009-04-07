--- src/arch/i386/x86_floatmul.c.orig	2005-12-21 22:06:35.000000000 +0300
+++ src/arch/i386/x86_floatmul.c	2009-04-04 04:53:56.000000000 +0400
@@ -46,7 +46,7 @@
 		v4hi temp;
 		
 		
-		samples_pre = MMX_ALIGN - (aint)bpt % MMX_ALIGN;
+		samples_pre = (MMX_ALIGN - (aint)bpt % MMX_ALIGN) % MMX_ALIGN;
 		samples_pre /= sizeof(ALshort);
 		samples_main = len - samples_pre;
 		samples_post = samples_main % 8;
