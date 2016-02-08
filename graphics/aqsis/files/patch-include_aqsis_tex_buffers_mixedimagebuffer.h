--- include/aqsis/tex/buffers/mixedimagebuffer.h.orig	2012-08-24 12:26:50 UTC
+++ include/aqsis/tex/buffers/mixedimagebuffer.h
@@ -45,9 +45,11 @@
 #include <string>
 #include <vector>
 
+#ifndef Q_MOC_RUN
 #include <boost/shared_array.hpp>
 #include <boost/shared_ptr.hpp>
 #include <boost/utility.hpp>
+#endif
 
 #include <aqsis/math/math.h>
 #include <aqsis/tex/buffers/channellist.h>
