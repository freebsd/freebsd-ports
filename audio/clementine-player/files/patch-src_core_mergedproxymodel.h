--- src/core/mergedproxymodel.h.orig	2014-04-23 10:16:44 UTC
+++ src/core/mergedproxymodel.h
@@ -25,10 +25,12 @@
 using std::placeholders::_1;
 using std::placeholders::_2;
 
+#ifndef Q_MOC_RUN
 #include <boost/multi_index_container.hpp>
 #include <boost/multi_index/member.hpp>
 #include <boost/multi_index/ordered_index.hpp>
 #include <boost/multi_index/hashed_index.hpp>
+#endif
 
 using boost::multi_index::multi_index_container;
 using boost::multi_index::indexed_by;
