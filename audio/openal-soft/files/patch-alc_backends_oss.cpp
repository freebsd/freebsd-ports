Backport upstream commits to fix build.

https://github.com/kcat/openal-soft/commit/278d1dc4d607b84e4e7b2d93af094d7932588962
https://github.com/kcat/openal-soft/commit/b93a15cc886cda8ce7626e84c637bdaf7c346773

https://github.com/kcat/openal-soft/issues/1215

--- alc/backends/oss.cpp.orig	2025-12-22 09:17:45 UTC
+++ alc/backends/oss.cpp
@@ -121,7 +121,7 @@ class FileHandle { (public)
     ~FileHandle() { if(mFd != -1) ::close(mFd); }
 
     template<typename ...Args>
-    [[nodiscard]] auto open(const char *fname, Args&& ...args) -> bool
+    [[nodiscard]] auto open(gsl::czstring const fname, Args&& ...args) -> bool
     {
         close();
         mFd = ::open(fname, std::forward<Args>(args)...);
@@ -149,21 +149,25 @@ void ALCossListAppend(std::vector<DevMap> &list, std::
             if(strncmp(path.data() + i, handle.data() + hoffset, path.size() - i) == 0)
                 handle = handle.substr(0, hoffset);
             path = path.substr(0, i);
+            break;
         }
     }
 #endif
-    if(handle.empty())
-        handle = path;
+    if(path.empty())
+        return;
 
     if(std::ranges::find(list, path, &DevMap::device_name) != list.end())
         return;
 
+    if(handle.empty())
+        handle = path;
+
     auto count = 1;
     auto newname = std::string{handle};
     while(std::ranges::find(list, newname, &DevMap::name) != list.end())
         newname = al::format("{} #{}", handle, ++count);
 
-    const auto &entry = list.emplace_back(std::move(newname), path);
+    const auto &entry = list.emplace_back(std::move(newname), std::string{path});
     TRACE("Got device \"{}\", \"{}\"", entry.name, entry.device_name);
 }
 
@@ -208,16 +212,12 @@ done:
 done:
     file.close();
 
-    const char *defdev{((type_flag==DSP_CAP_INPUT) ? DefaultCapture : DefaultPlayback).c_str()};
-    auto iter = std::ranges::find(devlist, defdev, &DevMap::device_name);
-    if(iter == devlist.end())
-        devlist.insert(devlist.begin(), DevMap{GetDefaultName(), defdev});
+    auto const &defdev = (type_flag == DSP_CAP_INPUT) ? DefaultCapture : DefaultPlayback;
+    if(auto const iter = std::ranges::find(devlist, defdev, &DevMap::device_name);
+        iter != devlist.end())
+        std::ranges::rotate(devlist.begin(), iter, iter+1);
     else
-    {
-        auto entry = DevMap{std::move(*iter)};
-        devlist.erase(iter);
-        devlist.insert(devlist.begin(), std::move(entry));
-    }
+        devlist.insert(devlist.begin(), DevMap{std::string{GetDefaultName()}, defdev});
     devlist.shrink_to_fit();
 }
 
