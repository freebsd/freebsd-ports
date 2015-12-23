--- mg_m_init.c.orig	2006-01-03 10:15:37 UTC
+++ mg_m_init.c
@@ -284,7 +284,7 @@ int mg_open_device _P2 ( (devname, block
     if (fd > 0)
     {
 	(void) close(0);
-	if (dup(fd) != 0)
+	if (dup2(fd,0) != 0)
 	{
 	    lprintf( L_FATAL, "mod: cannot make %s stdin", devname );
 	    return ERROR;
@@ -296,11 +296,11 @@ int mg_open_device _P2 ( (devname, block
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
