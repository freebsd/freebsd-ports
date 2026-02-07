--- api/logic/Version.cpp.orig	2020-05-30 15:28:28 UTC
+++ api/logic/Version.cpp
@@ -78,7 +78,7 @@ void Version::parse()
     // FIXME: this is bad. versions can contain a lot more separators...
     QStringList parts = m_string.split('.');
 
-    for (const auto part : parts)
+    for (const auto& part : parts)
     {
         m_sections.append(Section(part));
     }
