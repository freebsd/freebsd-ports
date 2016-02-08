--- tools/piqsl/displayserverimage.cpp.orig	2012-08-24 12:26:50 UTC
+++ tools/piqsl/displayserverimage.cpp
@@ -39,11 +39,13 @@
 #include	<map>
 #include	<algorithm>
 
+#ifndef Q_MOC_RUN
 #include	<boost/archive/iterators/base64_from_binary.hpp>
 #include	<boost/archive/iterators/transform_width.hpp>
 #include	<boost/archive/iterators/insert_linebreaks.hpp>
 #include	<boost/format.hpp>
 #include	<boost/filesystem.hpp>
+#endif
 
 #include	"displayserverimage.h"
 
