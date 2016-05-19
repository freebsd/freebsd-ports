--- src/glocal/score.cpp.orig	2006-09-14 20:40:19 UTC
+++ src/glocal/score.cpp
@@ -2,7 +2,7 @@
 #include<score.h>
 #include<leftinfluence.h>
 #include<rightinfluence.h>
-#include<fstream.h>
+#include<fstream>
 
 extern vector<class Score*> scoreFunctions[1<<(UPSTRANDBITS+DOWNSTRANDBITS+RELPOSBITS)];
 
