# HG changeset patch
# User Chris <cspiel@users.sourceforge.net>
# Date 1455528030 -3600
# Node ID 73e6f16de80a94175db61f82ad10d4cd96790e85
# Parent  596efbff27a8271a4c20184163e72b5914e334bf
Fix issue #1537368 (additional patch): Get rid of `boost::assign::map_list_of'.

diff -r 596efbff27a8 -r 73e6f16de80a src/filespec.cc
--- src/filespec.cc.orig	2015-08-07 14:45:02 UTC
+++ src/filespec.cc
@@ -37,7 +37,6 @@
 #include <cctype>
 
 #include <boost/algorithm/string/case_conv.hpp>
-#include <boost/assign/list_of.hpp>
 
 #include <vigra/imageinfo.hxx>
 
@@ -412,17 +411,12 @@ class Globbing
 public:
     Globbing() : algorithm_name_("literal"), algorithm_(NULL)
     {
-        installed_algorithms_ =
-            boost::assign::map_list_of
-            ("literal", MAKE_ALGORITHM(new LiteralGlobbingAlgorithm))
-            ("wildcard", MAKE_ALGORITHM(new WildcardGlobbingAlgorithm))
-#ifndef _WIN32
-            ("shell", MAKE_ALGORITHM(new ShellGlobbingAlgorithm))
-#endif
-            ;
-
+        installed_algorithms_["literal"] = MAKE_ALGORITHM(new LiteralGlobbingAlgorithm);
+        installed_algorithms_["wildcard"] = MAKE_ALGORITHM(new WildcardGlobbingAlgorithm);
         setup_alias("literal", "none");
+
 #ifndef _WIN32
+        installed_algorithms_["shell"] = MAKE_ALGORITHM(new ShellGlobbingAlgorithm);
         setup_alias("shell", "sh");
 #endif
     }
