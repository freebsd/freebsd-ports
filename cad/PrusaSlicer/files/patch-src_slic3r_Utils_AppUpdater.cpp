--- src/slic3r/Utils/AppUpdater.cpp.orig	2024-10-15 09:13:05 UTC
+++ src/slic3r/Utils/AppUpdater.cpp
@@ -156,7 +156,7 @@ AppUpdater::priv::priv() :
 
 AppUpdater::priv::priv() :
 	m_cancel (false)
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     , m_default_dest_folder (boost::filesystem::path("/tmp"))
 #else
 	, m_default_dest_folder (boost::filesystem::path(data_dir()) / "cache")
