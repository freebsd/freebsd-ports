--- src/library/groupbydialog.h.orig	2014-04-23 10:16:44 UTC
+++ src/library/groupbydialog.h
@@ -25,9 +25,11 @@
 using std::placeholders::_1;
 using std::placeholders::_2;
 
+#ifndef Q_MOC_RUN
 #include <boost/multi_index_container.hpp>
 #include <boost/multi_index/member.hpp>
 #include <boost/multi_index/ordered_index.hpp>
+#endif
 
 #include "librarymodel.h"
 
