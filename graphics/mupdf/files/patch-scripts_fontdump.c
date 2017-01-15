--- scripts/fontdump.c.orig	2016-11-28 13:34:04 UTC
+++ scripts/fontdump.c
@@ -50,7 +50,6 @@ main(int argc, char **argv)
 	fprintf(fo, "#ifndef __STRICT_ANSI__\n");
 	fprintf(fo, "#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)\n");
 	fprintf(fo, "#if !defined(__ICC)\n");
-	fprintf(fo, "#define HAVE_INCBIN\n");
 	fprintf(fo, "#endif\n");
 	fprintf(fo, "#endif\n");
 	fprintf(fo, "#endif\n");
