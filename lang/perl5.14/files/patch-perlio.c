$FreeBSD$

--- perlio.c.orig	Wed Feb  2 16:45:24 2005
+++ perlio.c	Wed Feb  2 16:45:34 2005
@@ -454,7 +454,7 @@ PerlIO_debug(const char *fmt, ...)
     va_list ap;
     dSYS;
     va_start(ap, fmt);
-    if (!dbg) {
+    if (!dbg && !PL_tainting && PL_uid == PL_euid && PL_gid == PL_egid) {
 	char *s = PerlEnv_getenv("PERLIO_DEBUG");
 	if (s && *s)
 	    dbg = PerlLIO_open3(s, O_WRONLY | O_CREAT | O_APPEND, 0666);
@@ -471,7 +471,7 @@ PerlIO_debug(const char *fmt, ...)
 	s = CopFILE(PL_curcop);
 	if (!s)
 	    s = "(none)";
-	sprintf(buffer, "%s:%" IVdf " ", s, (IV) CopLINE(PL_curcop));
+	sprintf(buffer, "%.40s:%" IVdf " ", s, (IV) CopLINE(PL_curcop));
 	len = strlen(buffer);
 	vsprintf(buffer+len, fmt, ap);
 	PerlLIO_write(dbg, buffer, strlen(buffer));
