$FreeBSD$

--- hack/hack.unix.c.orig	Thu Nov 20 10:17:36 2003
+++ hack/hack.unix.c	Thu Nov 20 10:18:09 2003
@@ -86,7 +86,7 @@
 /* old version - for people short of space */
 char *np;
 
-	name = "/usr/games/hide/hack";
+	name = "%%PREFIX%%/bin/hack";
 	if(stat(name, &hbuf))
 		error("Cannot get status of %s.",
 			(np = rindex(name, '/')) ? np+1 : name);
