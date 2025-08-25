--- src/qt/qt_vmmanager_detailsection.cpp.orig	2025-08-24 19:05:30 UTC
+++ src/qt/qt_vmmanager_detailsection.cpp
@@ -145,7 +145,7 @@ void
 }
 
 void
-VMManagerDetailSection::addSection(const QString &name, const QString &value, Display::Name displayField)
+VMManagerDetailSection::addSection(const QString &name, const QString &value, VMManager::Display::Name displayField)
 {
     const auto new_section = DetailSection { name, value};
     sections.push_back(new_section);
