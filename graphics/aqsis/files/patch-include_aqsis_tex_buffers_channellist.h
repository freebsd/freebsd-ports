--- include/aqsis/tex/buffers/channellist.h.orig	2012-08-24 12:26:50 UTC
+++ include/aqsis/tex/buffers/channellist.h
@@ -43,7 +43,9 @@
 #include <iosfwd>
 #include <vector>
 
+#ifndef Q_MOC_RUN
 #include <boost/format.hpp>
+#endif
 
 #include <aqsis/tex/buffers/channelinfo.h>
 #include <aqsis/tex/texexception.h>
