--- ../sal/osl/unx/security.c.orig	Sat Jul 20 22:53:31 2002
+++ ../sal/osl/unx/security.c	Sat Jul 20 22:52:39 2002
@@ -739,7 +739,7 @@
 	}
 
 
-#elif (LINUX && (GLIBC >= 2))
+#elif ((LINUX && (GLIBC >= 2)) || defined(FREEBSD))
 	
 	struct passwd	*pPasswd; 
 	
