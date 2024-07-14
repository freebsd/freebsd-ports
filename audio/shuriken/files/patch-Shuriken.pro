--- Shuriken.pro.orig	2024-07-14 17:04:28 UTC
+++ Shuriken.pro
@@ -13,9 +13,7 @@
         }
     }
 }
-QMAKE_CXXFLAGS += -msse \
-    -msse2 \
-    -std=c++11
+QMAKE_CXXFLAGS += -std=c++11
 nowarning: QMAKE_CXXFLAGS += -Wno-misleading-indentation \
     -Wno-unused-parameter
 nopie: QMAKE_LFLAGS += -no-pie
