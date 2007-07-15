--- paths.cc.orig	2007-05-07 14:13:44.000000000 +0000
+++ paths.cc	2007-07-15 22:17:32.000000000 +0000
@@ -10,6 +10,7 @@
 #include <string>
 #include <sstream>
 
+#include <boost/version.hpp>
 #include <boost/filesystem/operations.hpp>
 #include <boost/filesystem/convenience.hpp>
 
@@ -249,6 +250,41 @@
   I(fully_normalized_path_split(path, true, sp));
 }
 
+// path::normalize() is deprecated in Boost 1.34, and also
+// doesn't remove leading or trailing dots any more.
+static fs::path
+normalize_path(fs::path const & in)
+{
+#if BOOST_VERSION < 103400
+  return in.normalize();
+#else
+  fs::path out;
+  vector<string> stack;
+  for (fs::path::iterator i = in.begin(); i != in.end(); ++i)
+    {
+      // remove . elements
+      if (*i == ".")
+        continue;
+      // remove foo/.. element pairs
+      if (*i == "..")
+        {
+          if (!stack.empty())
+            {
+              stack.pop_back();
+              continue;
+            }
+        }
+      stack.push_back(*i);
+    }
+  for (vector<string>::const_iterator i = stack.begin();
+       i != stack.end(); ++i)
+    {
+      out /= *i;
+    }
+  return out;
+#endif
+}
+
 static void
 normalize_external_path(string const & path, string & normalized)
 {
@@ -272,7 +308,7 @@
           base = initial_rel_path.get();
           // the fs::native is needed to get it to accept paths like ".foo".
           relative = fs::path(path, fs::native);
-          out = (base / relative).normalize();
+          out = normalize_path(base / relative);
         }
       catch (exception &)
         {
@@ -539,9 +575,9 @@
 normalize_out_dots(string const & path)
 {
 #ifdef WIN32
-  return fs::path(path, fs::native).normalize().string();
+  return normalize_path(fs::path(path, fs::native)).string();
 #else
-  return fs::path(path, fs::native).normalize().native_file_string();
+  return normalize_path(fs::path(path, fs::native)).native_file_string();
 #endif
 }
 
@@ -679,9 +715,17 @@
     }
 
   // check for _MTN/. and _MTN/.. to see if mt dir is readable
-  if (!fs::exists(check / ".") || !fs::exists(check / ".."))
+  try
+    {
+      if (!fs::exists(check / ".") || !fs::exists(check / ".."))
+        {
+          L(FL("problems with '%s' (missing '.' or '..')") % check.string());
+          return false;
+        }
+    }
+  catch(exception &)
     {
-      L(FL("problems with '%s' (missing '.' or '..')") % check.string());
+      L(FL("problems with '%s' (cannot check for '.' or '..')") % check.string());
       return false;
     }
   return true;
