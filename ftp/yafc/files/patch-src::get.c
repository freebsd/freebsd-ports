--- src/get.c.orig	Mon May 10 17:24:10 2004
+++ src/get.c	Mon May 10 17:25:04 2004
@@ -279,7 +279,7 @@
 				e = xstrdup(ctime(&sb.st_mtime));
 				a = ask(ASKYES|ASKNO|ASKUNIQUE|ASKCANCEL|ASKALL|ASKRESUME,
 						ASKRESUME,
-						_("Local file '%s' exists\nLocal: %ld bytes, %sRemote: %ld bytes, %sOverwrite?"),
+						_("Local file '%s' exists\nLocal: %lld bytes, %sRemote: %ld bytes, %sOverwrite?"),
 						shortpath(dest, 42, gvLocalHomeDir),
 						sb.st_size, e ? e : "unknown date",
 						ftp_filesize(fi->path), ctime(&ft));
