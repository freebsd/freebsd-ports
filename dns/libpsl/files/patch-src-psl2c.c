--- src/psl2c.c.orig	2015-09-23 12:52:04 UTC
+++ src/psl2c.c
@@ -246,7 +246,7 @@ int main(int argc, const char **argv)
 
 		_print_psl_entries(fpout, psl->suffixes, "suffixes");
 
-		snprintf(cmd, cmdsize, "sha1sum %s", argv[1]);
+		snprintf(cmd, cmdsize, "sha1 %s", argv[1]);
 		if ((pp = popen(cmd, "r"))) {
 			if (fscanf(pp, "%63[0-9a-zA-Z]", checksum) < 1)
 				*checksum = 0;
