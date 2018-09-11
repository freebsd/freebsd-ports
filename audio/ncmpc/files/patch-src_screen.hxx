--- src/screen.hxx.orig	2018-04-04 08:23:50 UTC
+++ src/screen.hxx
@@ -82,8 +82,7 @@ class ScreenManager { (public)
 	StatusBar status_bar;
 
 private:
-	using PageMap = std::map<const struct screen_functions *,
-				 std::unique_ptr<Page>>;
+	using PageMap = std::map<const struct screen_functions *, Page *>;
 	PageMap pages;
 	PageMap::iterator current_page = pages.begin();
 
@@ -120,7 +119,7 @@ class ScreenManager { (public)
 
 	gcc_pure
 	bool IsVisible(const Page &page) const {
-		return &page == current_page->second.get();
+		return &page == current_page->second;
 	}
 
 	void Switch(const struct screen_functions &sf, struct mpdclient &c);
