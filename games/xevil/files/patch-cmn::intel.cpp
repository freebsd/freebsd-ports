--- cmn/intel.cpp.orig	2012-05-27 06:52:29.000000000 +0900
+++ cmn/intel.cpp	2012-05-27 06:53:11.000000000 +0900
@@ -35,7 +35,7 @@
   #include <string.h>
 }
 #if X11
-#include <strstream.h>
+#include <sstream>
 #endif
 #if WIN32
 #include <strstrea.h>
@@ -50,6 +50,7 @@
 #include "xdata.h"
 
 
+using namespace std;
 
 // Defines
 #define FIGHT_RANGE 40 // made it smaller for Dogs 45  // [50-40]
@@ -212,7 +213,7 @@
 
 
 
-Intel::Intel(WorldP w,LocatorP l,char *name,
+Intel::Intel(WorldP w,LocatorP l,const char *name,
 	           const IntelOptions *ops,ITmask opMask) {
   intelStatusChanged = True;
   living = True;
@@ -755,7 +756,7 @@
 
 
 
-Human::Human(WorldP w,LocatorP l,char *name,int lves,
+Human::Human(WorldP w,LocatorP l,const char *name,int lves,
              int *sharedLves,ColorNum cNum)
 : Intel(w,l,name,NULL,ITnone) {
   lives = lves;
@@ -931,7 +932,7 @@
 
 
 
-Machine::Machine(WorldP w,LocatorP l,char *name,const IntelOptions *ops,
+Machine::Machine(WorldP w,LocatorP l,const char *name,const IntelOptions *ops,
 		 ITmask opMask) 
 : Intel(w,l,name,ops,opMask)
 {
@@ -1829,7 +1830,7 @@
 
 
 
-Enemy::Enemy(WorldP w,LocatorP l,char *name,
+Enemy::Enemy(WorldP w,LocatorP l,const char *name,
 	const IntelOptions *ops,ITmask opMask)
     :Machine(w,l,name,ops,opMask) {}
   
@@ -1854,7 +1855,7 @@
 
 
 
-Neutral::Neutral(WorldP w,LocatorP l,char *name,
+Neutral::Neutral(WorldP w,LocatorP l,const char *name,
 	const IntelOptions *ops,ITmask opMask)
 	  :Machine(w,l,name,ops,opMask) {}
   
@@ -1867,7 +1868,7 @@
 
 
 
-SealIntel::SealIntel(WorldP w,LocatorP l,char *name,const Id &home_id)
+SealIntel::SealIntel(WorldP w,LocatorP l,const char *name,const Id &home_id)
 :Neutral(w,l,name,NULL,ITnone)
 {
 //  Timer oTimer(LADDER_JUMP_TIME);
@@ -1906,7 +1907,7 @@
 
 
 
-DoppelIntel::DoppelIntel(WorldP w,LocatorP l,char *name,
+DoppelIntel::DoppelIntel(WorldP w,LocatorP l,const char *name,
 	  const IntelOptions *ops,ITmask opMask,IntelP master)
 		:Neutral(w,l,name,ops,opMask) {
   assert(master);
@@ -2073,7 +2074,7 @@
 
 
 
-Pet::Pet(WorldP w,LocatorP l,char *name,
+Pet::Pet(WorldP w,LocatorP l,const char *name,
 	const IntelOptions *ops,ITmask opMask,IntelP master)
 	  :DoppelIntel(w,l,name,ops,opMask,master) {
 	mode = Heel;
@@ -2095,7 +2096,7 @@
 	char buffer[80];
 	ostrstream str(buffer,80);
 	str << "mode changing from:" << Pet::mode_string(prev) <<
-		" to: " << Pet::mode_string(curr) << endl << ends;
+		" to: " << Pet::mode_string(curr) << endl;
 #if WIN32
 	TRACE(buffer);
 #endif
@@ -2308,7 +2309,7 @@
 
 
 
-char *Pet::mode_string(int mode) {
+const char *Pet::mode_string(int mode) {
 	switch (mode) {
 		case Heel:		
 			return "Heel";
