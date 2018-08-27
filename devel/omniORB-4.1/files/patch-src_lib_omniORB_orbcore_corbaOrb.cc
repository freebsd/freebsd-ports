corbaOrb.cc:1374:13: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
                        "-ORBid "ORB_ID_STRING" (standard option)") {}
                                 ^

--- src/lib/omniORB/orbcore/corbaOrb.cc.orig	2018-08-27 19:52:14 UTC
+++ src/lib/omniORB/orbcore/corbaOrb.cc
@@ -1371,13 +1371,13 @@ class idHandler : public orbOptions::Handler { (public
     orbOptions::Handler("id",
 			"id = " ORB_ID_STRING,
 			1,
-			"-ORBid "ORB_ID_STRING" (standard option)") {}
+			"-ORBid " ORB_ID_STRING " (standard option)") {}
 
 
   void visit(const char* value,orbOptions::Source) throw (orbOptions::BadParam) {
 
     if (!isValidId(value)) {
-      throw orbOptions::BadParam(key(),value,"id is not "ORB_ID_STRING);
+      throw orbOptions::BadParam(key(),value,"id is not " ORB_ID_STRING);
     }
     if( strcmp(value, myOrbId()) ) {
       if( omniORB::trace(1) ) {
@@ -1501,7 +1501,7 @@ class poa_iiop_portHandler : public orbOptions::Handle
   void visit(const char* value,orbOptions::Source) throw (orbOptions::BadParam) {
 
     throw orbOptions::BadParam(key(),value,
-			       "poa_iiop_port"POA_IIOP_IS_OBSOLETE);
+			       "poa_iiop_port" POA_IIOP_IS_OBSOLETE);
   }
 
   void dump(orbOptions::sequenceString& result) {
@@ -1520,7 +1520,7 @@ class poa_iiop_name_portHandler : public orbOptions::H
 
   void visit(const char* value,orbOptions::Source) throw (orbOptions::BadParam) {
     throw orbOptions::BadParam(key(),value,
-			       "poa_iiop_name_port"POA_IIOP_IS_OBSOLETE);
+			       "poa_iiop_name_port" POA_IIOP_IS_OBSOLETE);
   }
 
   void dump(orbOptions::sequenceString& result) {
