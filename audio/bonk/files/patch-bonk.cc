
$FreeBSD$

--- bonk.cc.orig	Fri Jun 14 16:18:52 2002
+++ bonk.cc	Fri Jun 14 16:19:13 2002
@@ -38,6 +38,8 @@
 #include <string>
 #include <algorithm>
 
+using namespace std;
+
 // Support from Linux and *BSD sound output
 
 #if defined(__linux__)
