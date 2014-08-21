--- build/src/libkawari/kawari_ns.cpp.orig
+++ build/src/libkawari/kawari_ns.cpp
@@ -18,6 +18,7 @@
 #include "misc/misc.h"
 using namespace kawari_log;
 //---------------------------------------------------------------------------
+#include <climits>
 using namespace std;
 //---------------------------------------------------------------------------
 // 範囲外のインデックス
