--- src/put.c.orig	Mon May 10 17:25:01 2004
+++ src/put.c	Mon May 10 17:25:36 2004
@@ -217,7 +217,7 @@
 				e = xstrdup(ctime(&sb->st_mtime));
 				a = ask(ASKYES|ASKNO|ASKUNIQUE|ASKCANCEL|ASKALL|ASKRESUME,
 						ASKRESUME,
-						_("Remote file '%s' exists\nLocal: %ld bytes, %sRemote: %ld bytes, %sOverwrite?"),
+						_("Remote file '%s' exists\nLocal: %lld bytes, %sRemote: %ld bytes, %sOverwrite?"),
 						shortpath(dest, 42, ftp->homedir),
 						sb->st_size, e ? e : "unknown date",
 						ftp_filesize(f->path), ctime(&ft));
