--- src/gexecute.cpp.orig	2015-08-03 10:49:16 UTC
+++ src/gexecute.cpp
@@ -32,6 +32,8 @@
 #include <wx/stdpaths.h>
 #include <wx/filename.h>
 
+#include <sstream>
+
 #include "gexecute.h"
 #include "errors.h"
 #include "chooselang.h"
@@ -49,6 +51,14 @@
     using std::regex_match;
 #endif
 
+static int strtoi(const std::string& s)
+{
+  std::istringstream str(s);
+  int i;
+  str >> i;
+  return i;
+}
+
 namespace
 {
 
@@ -186,7 +196,8 @@ bool ExecuteGettextAndParseOutput(const 
         wsmatch match;
         if (regex_match(e, match, RE_ERROR))
         {
-            rec.line = std::stoi(match.str(1));
+            std::string str(match.str(1).begin(),match.str(2).end());
+            rec.line = strtoi(str);
             rec.text = match.str(3);
             errors.push_back(rec);
             wxLogTrace("poedit.execute",
