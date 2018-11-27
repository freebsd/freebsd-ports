--- src/ai.cpp.orig	2018-10-31 18:46:12 UTC
+++ src/ai.cpp
@@ -22,6 +22,8 @@
 /*	This file is contains the AI logic.
  */
 
 #include "ai.h"
+#include <algorithm>
+#include <sys/limits.h>
 
 AI::AI(BlokishBoard &board)
