--- udcli/udcli.c.orig	Sun Aug  6 16:39:07 2006
+++ udcli/udcli.c	Sun Aug  6 16:39:31 2006
@@ -95,8 +95,8 @@
 		}
 	else if (strcmp(*argv,"-c") == 0)
 		if (--argc) {
-			o_do_count= 1;
 			char* s = *(++argv);
+			o_do_count= 1;
 			if (sscanf(s, "%lld", &o_count) == 0)
 				fprintf(stderr, "Invalid value given for -c.\n");
 		} else { 
