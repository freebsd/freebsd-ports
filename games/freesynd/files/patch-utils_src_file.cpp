--- utils/src/file.cpp.orig	2024-05-15 21:07:46 UTC
+++ utils/src/file.cpp
@@ -356,8 +356,8 @@ void File::setOriginalDataFolder(const std::string& pa
 #if defined(__APPLE__)
     // Under Mac, it can't be in the bundle as user should not access it
 #else
-    // Under Windows/unix it's in the same directory as our data
-    dataPath_ = ourDataPath_;
+    // Under Windows/unix it's in the data subdirectory of our data
+    dataPath_ = ourDataPath_ / "data";
 #endif
     }
     LOG(Log::k_FLG_IO, "File", "setOriginalDataPath", ("set data path to %s", dataPath_.string().c_str()));
