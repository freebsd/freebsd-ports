--- source/ircaux.c.orig	Thu Oct  3 21:16:38 2002
+++ source/ircaux.c	Wed Dec 10 23:10:54 2003
@@ -861,20 +861,19 @@
 	err = getaddrinfo(localhost, localport, &hintsx, &res0x);
 
 	if (err != 0)
-#if defined(__linux__) && 0
-		/*
-		 * Due to bug in glibc implementation in getaddrinfo() we always
-		 * return -10.   This will be fixed, soon
-		 */
-		return -10;
-#else
 	{
+		# ifndef EAI_ADDRFAMILY
+		#  ifdef EAI_FAMILY
+		#   define EAI_ADDRFAMILY EAI_FAMILY
+		#  else
+		#   error "no EAI_ADDRFAMILY or EAI_FAMILY"
+		#  endif
+		# endif
 		if (err == EAI_ADDRFAMILY)
 			return -10;
 		else
 			return -2;
 	}
-#endif
 	err = -1;
 	for (resx = res0x; resx; resx = resx->ai_next)
 	{
