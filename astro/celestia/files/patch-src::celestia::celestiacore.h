--- src/celestia/celestiacore.h.orig	Sat Aug 30 21:30:15 2003
+++ src/celestia/celestiacore.h	Sat Aug 30 21:30:40 2003
@@ -126,8 +126,8 @@
     void readFavoritesFile();
     void writeFavoritesFile();
     void activateFavorite(FavoritesEntry&);
-    void addFavorite(std::string, std::string, FavoritesList::const_iterator* iter=NULL);
-    void addFavoriteFolder(std::string, FavoritesList::const_iterator* iter=NULL);
+    void addFavorite(std::string, std::string, FavoritesList::iterator* iter=NULL);
+    void addFavoriteFolder(std::string, FavoritesList::iterator* iter=NULL);
     const FavoritesList* getFavorites();
 
     const DestinationList* getDestinations();
