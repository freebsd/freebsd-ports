--- ./orb/security/audit_impl.cc.orig	2014-10-17 19:05:46.000000000 -0500
+++ ./orb/security/audit_impl.cc	2014-10-17 19:09:16.000000000 -0500
@@ -403,9 +403,9 @@
 
 #endif
 
-MICOSL2::ConsoleArchive::ConsoleArchive(int priority = 0)
+MICOSL2::ConsoleArchive::ConsoleArchive(int priority)
 {
-    priority_ = priority;
+    priority_ = priority = 0;
 }
 
 MICOSL2::ConsoleArchive::~ConsoleArchive()
