--- bonnie++.cpp.orig	Mon Aug 20 00:39:12 2001
+++ bonnie++.cpp	Fri Nov  2 19:54:31 2001
@@ -172,7 +172,6 @@
 #endif
 
   int int_c;
-  optind = 0;
   while(-1 != (int_c = getopt(argc, argv, "bd:fg:m:n:p:qr:s:u:x:y")) )
   {
     switch(char(int_c))
