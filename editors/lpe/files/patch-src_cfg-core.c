
$FreeBSD$

--- src/cfg-core.c	2001/04/08 15:27:13	1.1
+++ src/cfg-core.c	2001/04/08 15:27:39
@@ -62,7 +62,7 @@
     /* 
      * We search for "\n[name]=" in the lookup table...
      */
-    t_sstring = (char *) malloc (strlen (name) + 5);
+    t_sstring = (char *) alloca (strlen (name) + 5);
     sprintf (t_sstring, "\n%s=", name);
     if ((t_hentry = strstr (LpeOptionHash, t_sstring)) != NULL)
     {
