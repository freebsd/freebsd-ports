--- src/main.cc.orig	2009-01-24 15:25:10 UTC
+++ src/main.cc
@@ -5480,7 +5480,7 @@ main(int argc, char *argv[], char *envp[
 			{ 0, 0, 0, 0}
 		};
 		
-		c = getopt_long(argc, argv, "28a:c:df:hl:m:no:p:qRr:s:t:v", long_options,
+		c = getopt_long_only(argc, argv, "28a:c:df:hl:m:no:p:qRr:s:t:v", long_options,
 			&long_index);
 
 		if (c == EOF)
