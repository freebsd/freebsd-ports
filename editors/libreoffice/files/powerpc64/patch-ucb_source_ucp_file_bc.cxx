--- ucb/source/ucp/file/bc.cxx.orig	2020-12-08 05:01:04 UTC
+++ ucb/source/ucp/file/bc.cxx
@@ -40,6 +40,7 @@
 #include "prov.hxx"
 #include "filerror.hxx"
 #include "filinsreq.hxx"
+#pragma clang optimize off
 
 using namespace fileaccess;
 using namespace com::sun::star;
