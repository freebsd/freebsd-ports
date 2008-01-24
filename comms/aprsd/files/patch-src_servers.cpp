--- src/servers.cpp.orig	2003-10-01 12:58:27.000000000 -0400
+++ src/servers.cpp	2008-01-23 23:26:01.000000000 -0500
@@ -2627,7 +2627,6 @@
                                  &hostinfo,
                                  &h_err);
 
-
         if (rc || (hostinfo == NULL)){
             char* cp = new char[256];
             memset(cp, 0, 256);
@@ -3277,7 +3276,7 @@
 
 //----------------------------------------------------------------------
 
-inline string convertUpTime(int dTime)
+string convertUpTime(int dTime)
 {
     std::ostringstream ostr;
     int x;
