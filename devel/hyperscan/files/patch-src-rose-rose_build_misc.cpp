--- src/rose/rose_build_misc.cpp.orig	2016-06-24 12:15:55.919040000 +0100
+++ src/rose/rose_build_misc.cpp	2016-06-24 12:16:42.747695000 +0100
@@ -880,7 +880,7 @@
 class OutfixAllReports : public boost::static_visitor<set<ReportID>> {
 public:
     set<ReportID> operator()(const boost::blank &) const {
-        return {};
+        return set<ReportID>();
     }
 
     template<class T>
