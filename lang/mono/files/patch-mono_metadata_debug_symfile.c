--- mono/metadata/debug-symfile.c.orig	Tue Sep 10 14:21:57 2002
+++ mono/metadata/debug-symfile.c	Tue Sep 10 14:23:17 2002
@@ -2,6 +2,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <signal.h>
+#include <sys/param.h>
 #include <mono/metadata/metadata.h>
 #include <mono/metadata/rawbuffer.h>
 #include <mono/metadata/tokentype.h>
@@ -165,7 +166,7 @@
 get_sections (MonoDebugSymbolFile *symfile, gboolean emit_warnings)
 {
 #ifdef HAVE_ELF_H
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) && __FreeBSD_version < 500023
 	static const char ELFMAG[] = { ELFMAG0, ELFMAG1, ELFMAG2, ELFMAG3, 0 };
 #endif
 	if (!strncmp (symfile->raw_contents, ELFMAG, strlen (ELFMAG)))
