--- ./common/textsplit.cpp.orig	2013-09-30 18:45:05.000000000 +0200
+++ ./common/textsplit.cpp	2013-10-29 15:57:51.000000000 +0100
@@ -23,8 +23,9 @@
 #include <iostream>
 #include <string>
 #include <algorithm>
-#include <tr1/unordered_set>
 #include <cstring>
+#include "unordered_defs.h"
+using namespace std;
 
 #include "textsplit.h"
 #include "debuglog.h"
@@ -32,9 +33,6 @@
 #include "utf8iter.h"
 #include "uproplist.h"
 
-using std::tr1::unordered_set;
-using namespace std;
-
 
 /**
  * Splitting a text into words. The code in this file works with utf-8
@@ -60,9 +58,9 @@
 // of Unicode properties, but seems to do the job well enough in most
 // common cases
 static vector<unsigned int> vpuncblocks;
-static unordered_set<unsigned int> spunc;
-static unordered_set<unsigned int> visiblewhite;
-static unordered_set<unsigned int> sskip;
+static STD_UNORDERED_SET<unsigned int> spunc;
+static STD_UNORDERED_SET<unsigned int> visiblewhite;
+static STD_UNORDERED_SET<unsigned int> sskip;
 
 class CharClassInit {
 public:
