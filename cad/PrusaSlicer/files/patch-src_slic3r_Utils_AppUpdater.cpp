--- src/slic3r/Utils/AppUpdater.cpp.orig	2024-12-20 11:54:34 UTC
+++ src/slic3r/Utils/AppUpdater.cpp
@@ -157,7 +157,7 @@ AppUpdater::priv::priv() :
 
 AppUpdater::priv::priv() :
 	m_cancel (false)
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     , m_default_dest_folder (boost::filesystem::path("/tmp"))
 #else
 	, m_default_dest_folder (boost::filesystem::path(data_dir()) / "cache")
