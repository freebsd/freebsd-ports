--- src/psl2c.c.orig	2016-01-02 13:38:37 UTC
+++ src/psl2c.c
@@ -271,7 +271,7 @@ int main(int argc, const char **argv)
 
 		_print_psl_entries_dafsa(fpout, psl->suffixes);
 
-		snprintf(cmd, cmdsize, "sha1sum %s", argv[argpos]);
+		snprintf(cmd, cmdsize, "sha1 %s", argv[argpos]);
 		if ((pp = popen(cmd, "r"))) {
 			if (fscanf(pp, "%63[0-9a-zA-Z]", checksum) < 1)
 				*checksum = 0;
