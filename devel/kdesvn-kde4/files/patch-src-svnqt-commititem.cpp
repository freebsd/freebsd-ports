--- src/svnqt/commititem.cpp~	2009-04-14 19:47:55.000000000 +0200
+++ src/svnqt/commititem.cpp	2009-04-14 19:48:06.000000000 +0200
@@ -20,6 +20,7 @@
 #include "commititem.hpp"
 
 #include <svn_client.h>
+#include <svn_props.h>
 
 namespace svn {
 
