
$FreeBSD$

--- src/main.cc.orig	Wed Sep 10 06:22:55 2003
+++ src/main.cc	Sat Dec  6 00:36:09 2003
@@ -413,7 +413,7 @@
 			{ 0, 0, 0, 0}
 		};
 		
-		c = getopt_long_only(argc, argv, "28a:c:df:hl:m:no:p:qRr:s:t:v", long_options,
+		c = getopt_long(argc, argv, "28a:c:df:hl:m:no:p:qRr:s:t:v", long_options,
 			&long_index);
 
 		if (c == EOF)
