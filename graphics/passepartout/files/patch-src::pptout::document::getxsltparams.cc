--- src/pptout/document/getxsltparams.cc.orig	Sun Jan 18 00:22:12 2004
+++ src/pptout/document/getxsltparams.cc	Sun Jan 18 00:22:54 2004
@@ -3,6 +3,7 @@
 ///
 #include <libxml++/libxml++.h>
 #include <fstream>
+#include <algorithm>
 
 class XsltParamsFinder : public xmlpp::SaxParser {
 public:
