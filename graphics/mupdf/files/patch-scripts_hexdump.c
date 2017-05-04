--- scripts/hexdump.c.orig	2017-04-05 11:02:21 UTC
+++ scripts/hexdump.c
@@ -50,7 +50,6 @@ main(int argc, char **argv)
 	fprintf(fo, "#ifndef __STRICT_ANSI__\n");
 	fprintf(fo, "#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)\n");
 	fprintf(fo, "#if !defined(__ICC) && !defined(__ANDROID__)\n");
-	fprintf(fo, "#define HAVE_INCBIN\n");
 	fprintf(fo, "#endif\n");
 	fprintf(fo, "#endif\n");
 	fprintf(fo, "#endif\n");
