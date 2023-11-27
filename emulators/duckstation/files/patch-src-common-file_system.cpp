Fix an off-by-one '..' error when computing bios SearchPath

A '..' is missing in returned path when 'path' and 'relative_to' have no common
components. C++17's std::filesystem::relative() method returns a correct value.

As an alternative to that simple patch, we may want to just replace
Path::MakeRelative() calls by std::filesystem::relative() calls and remove
Path::MakeRelative() method.

--- src/common/file_system.cpp.orig	2023-10-16 12:57:57 UTC
+++ src/common/file_system.cpp
@@ -12,6 +12,7 @@
 #include <cstdlib>
 #include <cstring>
 #include <limits>
+#include <filesystem>
 
 #ifdef __APPLE__
 #include <mach-o/dyld.h>
@@ -250,49 +251,7 @@ std::string Path::MakeRelative(const std::string_view&
 
 std::string Path::MakeRelative(const std::string_view& path, const std::string_view& relative_to)
 {
-  // simple algorithm, we just work on the components. could probably be better, but it'll do for now.
-  std::vector<std::string_view> path_components(SplitNativePath(path));
-  std::vector<std::string_view> relative_components(SplitNativePath(relative_to));
-  std::vector<std::string_view> new_components;
-
-  // both must be absolute paths
-  if (Path::IsAbsolute(path) && Path::IsAbsolute(relative_to))
-  {
-    // find the number of same components
-    size_t num_same = 0;
-    for (size_t i = 0; i < path_components.size() && i < relative_components.size(); i++)
-    {
-      if (path_components[i] == relative_components[i])
-        num_same++;
-      else
-        break;
-    }
-
-    // we need at least one same component
-    if (num_same > 0)
-    {
-      // from the relative_to directory, back up to the start of the common components
-      const size_t num_ups = relative_components.size() - num_same;
-      for (size_t i = 0; i < num_ups; i++)
-        new_components.emplace_back("..");
-
-      // and add the remainder of the path components
-      for (size_t i = num_same; i < path_components.size(); i++)
-        new_components.push_back(std::move(path_components[i]));
-    }
-    else
-    {
-      // no similarity
-      new_components = std::move(path_components);
-    }
-  }
-  else
-  {
-    // not absolute
-    new_components = std::move(path_components);
-  }
-
-  return JoinNativePath(new_components);
+  return std::filesystem::relative(path, relative_to);
 }
 
 std::string_view Path::GetExtension(const std::string_view& path)
