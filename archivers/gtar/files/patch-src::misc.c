
$FreeBSD$

--- src/misc.c.orig	Mon Aug 27 01:14:26 2001
+++ src/misc.c	Wed Oct  2 19:10:55 2002
@@ -214,6 +214,13 @@
 	    return 0;
 	}
       while (! ISSLASH (*p));
+
+      do
+	{
+	  if (! *p++)
+	    return 0;
+	}
+      while ( ISSLASH (*p));
     }
 }
 
@@ -549,10 +556,8 @@
 chmod_error_details (char const *name, mode_t mode)
 {
   int e = errno;
-  char buf[10];
-  decode_mode (mode, buf);
-  ERROR ((0, e, _("%s: Cannot change mode to %s"),
-	  quotearg_colon (name), buf));
+  ERROR ((0, e, _("%s: Cannot change mode to 0%o"),
+	  quotearg_colon (name), mode));
 }
 
 void
