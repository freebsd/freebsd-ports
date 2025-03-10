--- gnuradio-runtime/lib/prefs.cc.orig	2021-09-30 14:10:55 UTC
+++ gnuradio-runtime/lib/prefs.cc
@@ -32,6 +32,7 @@
 #include <fstream>
 #include <iostream>
 
+#include <boost/filesystem/directory.hpp>
 #include <boost/filesystem/fstream.hpp>
 #include <boost/filesystem/operations.hpp>
 #include <boost/filesystem/path.hpp>
