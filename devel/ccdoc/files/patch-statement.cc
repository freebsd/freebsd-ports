$FreeBSD$

--- statement.cc.orig	Tue Feb 17 10:31:50 2004
+++ statement.cc	Tue Feb 17 10:32:53 2004
@@ -975,18 +975,18 @@
   // Define the search strings.
   // ================================================
   const char* prefixes[] = {
-    {"dll_"},{"DLL_"},
-    {"include_"},{"INCLUDE_"},
-    {"included_"},{"INCLUDED_"},
-    0 };
+    "dll_","DLL_",
+    "include_","INCLUDE_",
+    "included_","INCLUDED_",
+    NULL };
   const char* suffixes[] = {
-    {"_dll"},{"_DLL"},
-    {"_h"},{"_H"},
-    {"_hh"},{"_HH"},
-    {"_include"},{"_INCLUDE"},
-    {"_included"},{"_INCLUDED"},
-    {"_included_"},{"_INCLUDED_"},
-    0 };
+    "_dll","_DLL",
+    "_h","_H",
+    "_hh","_HH",
+    "_include","_INCLUDE",
+    "_included","_INCLUDED",
+    "_included_","_INCLUDED_",
+    NULL };
   // ================================================
   // Check the prefixes.
   // ================================================
