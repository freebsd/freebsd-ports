--- chrome/browser/ui/omnibox/chrome_omnibox_client.cc.orig	2023-10-19 19:58:07 UTC
+++ chrome/browser/ui/omnibox/chrome_omnibox_client.cc
@@ -474,10 +474,18 @@ void ChromeOmniboxClient::OnAutocompleteAccept(
               alternative_nav_match);
 
   // Store the details necessary to open the omnibox match via browser commands.
+#if defined(__clang__) && (__clang_major__ >= 16)
   location_bar_->set_navigation_params(LocationBar::NavigationParams(
       destination_url, disposition, transition, match_selection_timestamp,
       destination_url_entered_without_scheme,
       destination_url_entered_with_http_scheme));
+#else
+  LocationBar::NavigationParams np = {
+      destination_url, disposition, transition, match_selection_timestamp,
+      destination_url_entered_without_scheme,
+      destination_url_entered_with_http_scheme };
+  location_bar_->set_navigation_params(np);
+#endif
 
   if (browser_) {
     auto navigation = chrome::OpenCurrentURL(browser_);
