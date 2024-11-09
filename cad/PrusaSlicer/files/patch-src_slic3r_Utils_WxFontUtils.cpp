--- src/slic3r/Utils/WxFontUtils.cpp.orig	2024-09-18 13:39:04 UTC
+++ src/slic3r/Utils/WxFontUtils.cpp
@@ -19,7 +19,7 @@
 #include <wx/uri.h>
 #include <wx/fontutil.h> // wxNativeFontInfo
 #include <wx/osx/core/cfdictionary.h>
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include "slic3r/Utils/FontConfigHelp.hpp"
 #endif
 
@@ -83,7 +83,7 @@ bool WxFontUtils::can_load(const wxFont &font)
 #elif defined(__APPLE__)
     return true;
     //return is_valid_ttf(get_file_path(font));
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     return true;
     // font config check file path take about 4000ms for chech them all
     //std::string font_path = Slic3r::GUI::get_font_path(font);
@@ -104,7 +104,7 @@ std::unique_ptr<Emboss::FontFile> WxFontUtils::create_
         return nullptr; 
     }
     return Emboss::create_font_file(file_path.c_str());
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     std::string font_path = Slic3r::GUI::get_font_path(font);
     if (font_path.empty()){
         BOOST_LOG_TRIVIAL(error) << "Can not read font('" << get_human_readable_name(font) << "'), "
@@ -125,7 +125,7 @@ EmbossStyle::Type WxFontUtils::get_current_type()
     return EmbossStyle::Type::wx_win_font_descr;
 #elif defined(__APPLE__)
     return EmbossStyle::Type::wx_mac_font_descr;
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     return EmbossStyle::Type::wx_lin_font_descr;
 #else
     return EmbossStyle::Type::undefined;
