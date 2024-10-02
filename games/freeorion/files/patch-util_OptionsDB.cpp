--- util/OptionsDB.cpp.orig	2023-03-21 15:16:58 UTC
+++ util/OptionsDB.cpp
@@ -14,8 +14,7 @@
 #include <boost/algorithm/string/classification.hpp>
 #include <boost/algorithm/string/erase.hpp>
 #include <boost/algorithm/string/predicate.hpp>
-#include <boost/filesystem/fstream.hpp>
-#include <boost/filesystem/operations.hpp>
+#include <boost/filesystem.hpp>
 #include <boost/range/algorithm_ext/erase.hpp>
 #include <boost/tokenizer.hpp>
 
