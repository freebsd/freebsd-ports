--- file.c.orig	Tue Aug 27 10:14:57 2002
+++ file.c	Tue Aug 27 10:15:35 2002
@@ -2351,7 +2351,7 @@
 
 	    /* on failure, keep going */
 #if defined(HAVE_MKSTEMP) && defined(HAVE_MKDTEMP)
-	    result = (vl_mkdtemp(dirnam) == 0);
+	    result = (vl_mkdtemp(dirnam) != 0);
 #else
 	    result = (vl_mkdir(dirnam, 0700) == 0);
 #endif
