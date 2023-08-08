--- src/slic3r/GUI/OptionsGroup.cpp.orig	2023-07-25 12:28:59 UTC
+++ src/slic3r/GUI/OptionsGroup.cpp
@@ -1051,7 +1051,7 @@ void ogStaticText::SetPathEnd(const std::string& link)
 
 void ogStaticText::SetPathEnd(const std::string& link)
 {
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
     Bind(wxEVT_ENTER_WINDOW, [this, link](wxMouseEvent& event) {
         SetToolTip(OptionsGroup::get_url(get_app_config()->get("suppress_hyperlinks") != "1" ? link : std::string()));
@@ -1104,7 +1104,7 @@ void ogStaticText::FocusText(bool focus)
 
     SetFont(focus ? Slic3r::GUI::wxGetApp().link_font() :
         Slic3r::GUI::wxGetApp().normal_font());
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     this->GetContainingSizer()->Layout();
 #endif
     Refresh();
