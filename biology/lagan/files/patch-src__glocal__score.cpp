--- src/glocal/score.cpp.orig	2006-09-15 05:40:19.000000000 +0900
+++ src/glocal/score.cpp	2012-10-03 00:22:50.000000000 +0900
@@ -2,7 +2,7 @@
 #include<score.h>
 #include<leftinfluence.h>
 #include<rightinfluence.h>
-#include<fstream.h>
+#include<fstream>
 
 extern vector<class Score*> scoreFunctions[1<<(UPSTRANDBITS+DOWNSTRANDBITS+RELPOSBITS)];
 
