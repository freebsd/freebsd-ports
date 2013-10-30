--- ./rcldb/rclabstract.cpp.orig	2013-09-30 18:45:06.000000000 +0200
+++ ./rcldb/rclabstract.cpp	2013-10-29 15:57:51.000000000 +0100
@@ -19,8 +19,7 @@
 #include <math.h>
 
 #include <map>
-#include <tr1/unordered_set>
-using std::tr1::unordered_set;
+#include "unordered_defs.h"
 
 using namespace std;
 
@@ -284,7 +283,7 @@
     multimap<double, vector<string> > byQ;
     double totalweight = qualityTerms(docid, terms, byQ);
 
-    for (map<double, vector<string> >::reverse_iterator mit = byQ.rbegin(); 
+    for (multimap<double, vector<string> >::reverse_iterator mit = byQ.rbegin(); 
 	 mit != byQ.rend(); mit++) {
 	for (vector<string>::const_iterator qit = mit->second.begin();
 	     qit != mit->second.end(); qit++) {
@@ -362,7 +361,7 @@
     map<unsigned int, string> sparseDoc;
     // Also remember apart the search term positions so that we can list
     // them with their snippets.
-    unordered_set<unsigned int> searchTermPositions;
+    STD_UNORDERED_SET<unsigned int> searchTermPositions;
 
     // Remember max position. Used to stop walking positions lists while 
     // populating the adjacent slots.
@@ -385,7 +384,7 @@
     int ret = ABSRES_OK;
 
     // Let's go populate
-    for (map<double, vector<string> >::reverse_iterator mit = byQ.rbegin(); 
+    for (multimap<double, vector<string> >::reverse_iterator mit = byQ.rbegin(); 
 	 mit != byQ.rend(); mit++) {
 	unsigned int maxgrpoccs;
 	float q;
