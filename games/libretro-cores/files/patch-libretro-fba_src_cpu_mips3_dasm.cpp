--- libretro-fba/src/cpu/mips3/dasm.cpp.orig	2015-11-07 10:29:16 UTC
+++ libretro-fba/src/cpu/mips3/dasm.cpp
@@ -6,6 +6,9 @@
 #include <cstring>
 #include "mips3.h"
 #include "mipsdef.h"
+#include <cstdio>
+
+using namespace std;
 
 namespace mips
 {
