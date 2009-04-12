--- ./svnqt/commititem.cpp.orig	2008-05-25 12:01:46.000000000 +0400
+++ ./svnqt/commititem.cpp	2009-04-12 19:26:59.000000000 +0400
@@ -20,6 +20,7 @@
 #include "commititem.hpp"
 
 #include <svn_client.h>
+#include <svn_props.h>
 
 namespace svn {
 
