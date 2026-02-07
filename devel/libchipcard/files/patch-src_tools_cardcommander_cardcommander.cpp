Fix build with clang 6
cardcommander.cpp:48:47: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
  "cardcommander v0.4  (part of libchipcard v"k_CHIPCARD_VERSION_STRING")\n"\

--- src/tools/cardcommander/cardcommander.cpp.orig	2018-01-20 23:55:05 UTC
+++ src/tools/cardcommander/cardcommander.cpp
@@ -45,7 +45,7 @@
 using namespace std;
 
 #define k_PRG_VERSION_INFO \
-  "cardcommander v0.4  (part of libchipcard v"k_CHIPCARD_VERSION_STRING")\n"\
+  "cardcommander v0.4  (part of libchipcard v" k_CHIPCARD_VERSION_STRING ")\n"\
   "(c) 2006 Martin Preuss<martin@libchipcard.de>\n" \
   "This program is free software licensed under GPL.\n"\
   "See COPYING for details.\n"
