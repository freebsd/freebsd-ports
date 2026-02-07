--- src/slic3r/GUI/PresetArchiveDatabase.cpp.orig	2025-07-04 16:42:20 UTC
+++ src/slic3r/GUI/PresetArchiveDatabase.cpp
@@ -577,7 +577,7 @@ void PresetArchiveDatabase::load_app_manifest_json()
             if (const auto used = subtree.second.get_optional<bool>("has_installed_printers"); used) {
                 m_has_installed_printer_repositories_uuid[uuid] = *used;
             } else {
-                assert(false);
+//                assert(false);
                 m_has_installed_printer_repositories_uuid[uuid] = false;
             }
 			m_archive_repositories.emplace_back(std::make_unique<OnlineArchiveRepository>(std::move(uuid), std::move(manifest)));
