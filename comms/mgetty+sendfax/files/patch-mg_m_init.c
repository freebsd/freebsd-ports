--- mg_m_init.c.orig	Sat Nov 26 17:47:44 2005
+++ mg_m_init.c	Sat Dec 17 12:24:51 2005
@@ -269,7 +269,7 @@
     if (fd > 0)
     {
 	(void) close(0);
-	if (dup(fd) != 0)
+	if (dup2(fd,0) != 0)
 	{
 	    lprintf( L_FATAL, "mod: cannot make %s stdin", devname );
 	    return ERROR;
@@ -281,11 +281,11 @@
     (void) close(1);
     (void) close(2);
     
-    if (dup(0) != 1)
+    if (dup2(0,1) != 1)
     {
 	lprintf( L_FATAL, "mod: cannot dup to stdout"); return ERROR;
     }
-    if (dup(0) != 2)
+    if (dup2(0,2) != 2)
     {
 	lprintf( L_FATAL, "mod: cannot dup to stderr"); return ERROR;
     }
