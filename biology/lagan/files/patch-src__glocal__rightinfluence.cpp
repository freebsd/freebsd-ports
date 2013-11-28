--- src/glocal/rightinfluence.cpp.orig
+++ src/glocal/rightinfluence.cpp
@@ -1,6 +1,6 @@
 #include <rightinfluence.h>
 
-Fragment origin, end;
+Fragment origin, my_end;
 
 // Sets the first default owner of the whole region
 void initRI(RI *RightInfluence, long long int scoreIndex) {
@@ -18,17 +18,17 @@
 
 	// hack to aid winner selection
 	origin.score = -1;
-	end.score = -2;
-	origin.totalScore = end.totalScore = 0;
+	my_end.score = -2;
+	origin.totalScore = my_end.totalScore = 0;
 
 	// will win against anyone
-	end.seq1End = 0; end.seq2End = 0;
-	end.seq1Start = 0; end.seq2Start = 0;
+	my_end.seq1End = 0; my_end.seq2End = 0;
+	my_end.seq1Start = 0; my_end.seq2Start = 0;
 
 	origin.back = NULL;
 
     RightInfluence->act[-INF] = &origin;
-    RightInfluence->act[+INF] = &end;
+    RightInfluence->act[+INF] = &my_end;
 }
 
