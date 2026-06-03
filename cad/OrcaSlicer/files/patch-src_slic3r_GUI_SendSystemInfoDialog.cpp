--- src/slic3r/GUI/SendSystemInfoDialog.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/SendSystemInfoDialog.cpp
@@ -409,7 +409,7 @@ static std::string generate_system_info_json()
     data_node.put("Platform", platform_to_string(platform()));
     data_node.put("PlatformFlavor", platform_flavor_to_string(platform_flavor()));
     data_node.put("OSDescription", wxPlatformInfo::Get().GetOperatingSystemDescription().ToUTF8().data());
-#ifdef __linux__
+#if defined(__linux__)
     std::string distro_id = wxGetLinuxDistributionInfo().Id.ToUTF8().data(); // uses lsb-release
     std::string distro_ver = wxGetLinuxDistributionInfo().Release.ToUTF8().data();
     if (distro_id.empty()) { // lsb-release probably not available
