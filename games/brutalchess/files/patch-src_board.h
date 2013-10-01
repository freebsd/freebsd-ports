--- src/board.h.orig	2013-10-01 21:08:24.000000000 +0000
+++ src/board.h
@@ -12,6 +12,7 @@
 #include <cstdio>
 #include <iostream>
 #include <vector>
+#include <unistd.h>
 
 #include "bitboard.h"
 #include "boardmove.h"
