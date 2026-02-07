--- source/MaterialXFormat/File.cpp.orig	2025-09-15 18:12:11 UTC
+++ source/MaterialXFormat/File.cpp
@@ -23,6 +23,7 @@
     #include <linux/limits.h>
 #elif defined(__FreeBSD__)
     #include <sys/syslimits.h>
+    #include <sys/sysctl.h>
 #elif defined(__APPLE__)
     #include <mach-o/dyld.h>
 #endif
@@ -350,7 +351,7 @@ FilePath FilePath::getModulePath()
         }
     }
 #else
-    vector<char> buf(PATH_MAX);
+/*    vector<char> buf(PATH_MAX);
     while (true)
     {
         ssize_t reqSize = readlink("/proc/self/exe", buf.data(), buf.size());
@@ -367,8 +368,29 @@ FilePath FilePath::getModulePath()
             buf.data()[reqSize] = '\0';
             return FilePath(buf.data()).getParentPath();
         }
+    }*/
+
+    std::vector<char> buf(PATH_MAX);
+    size_t bufSize = buf.size();
+
+    int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
+    if (sysctl(mib, 4, buf.data(), &bufSize, nullptr, 0) == -1)
+    {
+        throw Exception("Error in getModulePath (FreeBSD): " + string(strerror(errno)));
     }
+
+    return FilePath(buf.data()).getParentPath();
 #endif
+}
+
+std::string getParentPath(const std::string &path)
+{
+    size_t lastSlash = path.find_last_of('/');
+    if (lastSlash == string::npos)
+    {
+        return ".";
+    }
+    return path.substr(0, lastSlash);
 }
 
 FileSearchPath getEnvironmentPath(const string& sep)
