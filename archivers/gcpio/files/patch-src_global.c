https://git.savannah.gnu.org/cgit/cpio.git/commit/src/global.c?id=641d3f489cf6238bb916368d4ba0d9325a235afb

--- src/global.c.orig	2019-11-03 15:07:23 UTC
+++ src/global.c
@@ -184,9 +184,6 @@ unsigned int warn_option = 0;
 /* Extract to standard output? */
 bool to_stdout_option = false;
 
-/* The name this program was run with.  */
-char *program_name;
-
 /* A pointer to either lstat or stat, depending on whether
    dereferencing of symlinks is done for input files.  */
 int (*xstat) ();
