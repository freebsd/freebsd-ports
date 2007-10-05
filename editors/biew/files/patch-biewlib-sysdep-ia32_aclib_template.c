--- biewlib/sysdep/ia32/aclib_template.c.orig	2002-12-13 16:31:20.000000000 +0100
+++ biewlib/sysdep/ia32/aclib_template.c	2007-10-04 15:22:15.000000000 +0200
@@ -209,8 +209,8 @@
 		MOVNTQ" %%mm6, 48(%1)\n"
 		MOVNTQ" %%mm7, 56(%1)\n"
 		:: "r" (from), "r" (to) : "memory");
-		((const unsigned char *)from)+=64;
-		((unsigned char *)to)+=64;
+		from = ((const unsigned char *)from)+64;
+		to = ((unsigned char *)to)+64;
 	}
 
 	// Pure Assembly cuz gcc is a bit unpredictable ;)
@@ -297,8 +297,8 @@
 		MOVNTQ" %%mm6, 48(%1)\n"
 		MOVNTQ" %%mm7, 56(%1)\n"
 		:: "r" (from), "r" (to) : "memory");
-		((const unsigned char *)from)+=64;
-		((unsigned char *)to)+=64;
+		from = ((const unsigned char *)from)+64;
+		to = ((unsigned char *)to)+64;
 	}
 
 #endif /* Have SSE */
@@ -393,7 +393,7 @@
 		MOVNTQ" %%mm0, 112(%0)\n"
 		MOVNTQ" %%mm0, 120(%0)\n"
 		:: "r" (to) : "memory");
-		((unsigned char *)to)+=128;
+		to = ((unsigned char *)to)+128;
 	}
 #endif /* Have SSE */
 #ifdef HAVE_MMX2
