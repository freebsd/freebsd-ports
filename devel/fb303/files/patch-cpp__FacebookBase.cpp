--- ./cpp/FacebookBase.cpp.orig	2013-08-15 18:04:29.000000000 +0400
+++ ./cpp/FacebookBase.cpp	2013-10-17 19:36:22.000000000 +0400
@@ -27,7 +27,7 @@
   aliveSince_ = (int64_t) time(NULL);
 }
 
-inline void FacebookBase::getName(std::string& _return) {
+void FacebookBase::getName(std::string& _return) {
   _return = name_;
 }
 
@@ -118,7 +118,7 @@
   return rv;
 }
 
-inline int64_t FacebookBase::aliveSince() {
+int64_t FacebookBase::aliveSince() {
   return aliveSince_;
 }
 
