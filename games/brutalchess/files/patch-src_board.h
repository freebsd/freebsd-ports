--- src/board.h.orig	2023-05-08 11:15:17 UTC
+++ src/board.h
@@ -12,6 +12,7 @@
 #include <cstdio>
 #include <iostream>
 #include <vector>
+#include <unistd.h>
 
 #include "bitboard.h"
 #include "boardmove.h"
