--- krosswordplayer/QzCrossWord.cpp.orig	Sat Aug 21 10:40:04 2004
+++ krosswordplayer/QzCrossWord.cpp	Sat Aug 21 10:40:13 2004
@@ -282,7 +282,7 @@
     }
 
     _gridLayout->activate();
-};
+}
 
 AcrossLitePuzzleBase* QzCrossWordGrid::puzzle () {
     return _puzzle;
