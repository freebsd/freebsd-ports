--- src/main.cc.orig	Tue Aug 29 08:54:53 2006
+++ src/main.cc	Tue Aug 29 08:55:01 2006
@@ -5448,7 +5448,7 @@
 			{ 0, 0, 0, 0}
 		};
 		
-		c = getopt_long(argc, argv, "28a:c:df:hl:m:no:p:qRr:s:t:v", long_options,
+		c = getopt_long_only(argc, argv, "28a:c:df:hl:m:no:p:qRr:s:t:v", long_options,
 			&long_index);
 
 		if (c == EOF)
