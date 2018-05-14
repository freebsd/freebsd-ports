--- menu.cpp.orig	2016-08-25 16:21:38 UTC
+++ menu.cpp
@@ -204,7 +204,7 @@ public:
         switch(t)
         {
           case 0:
-          sprintf(highScores[t], "SDL-BALL v "VERSION );
+          sprintf(highScores[t], "SDL-BALL v " VERSION );
           break;
           case 1:
           sprintf(highScores[t], "-----------------------");
