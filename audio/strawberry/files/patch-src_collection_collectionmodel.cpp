--- src/collection/collectionmodel.cpp.orig	2020-05-16 18:39:26 UTC
+++ src/collection/collectionmodel.cpp
@@ -119,12 +119,14 @@ CollectionModel::CollectionModel(CollectionBackend *ba
   }
 
   QIcon nocover = IconLoader::Load("cdcase");
-  no_cover_icon_ = nocover.pixmap(nocover.availableSizes().last()).scaled(kPrettyCoverSize, kPrettyCoverSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
-  //no_cover_icon_ = QPixmap(":/pictures/noalbumart.png").scaled(kPrettyCoverSize, kPrettyCoverSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
+  if (!nocover.isNull()) {
+    no_cover_icon_ = nocover.pixmap(nocover.availableSizes().last()).scaled(kPrettyCoverSize, kPrettyCoverSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
+  }
 
-  if (sIconCache == nullptr) {
+  if (app_ && !sIconCache) {
     sIconCache = new QNetworkDiskCache(this);
     sIconCache->setCacheDirectory(QStandardPaths::writableLocation(QStandardPaths::CacheLocation) + "/" + kPixmapDiskCacheDir);
+    connect(app_, SIGNAL(ClearPixmapDiskCache()), SLOT(ClearDiskCache()));
   }
 
   connect(backend_, SIGNAL(SongsDiscovered(SongList)), SLOT(SongsDiscovered(SongList)));
@@ -139,8 +141,6 @@ CollectionModel::CollectionModel(CollectionBackend *ba
   backend_->UpdateTotalArtistCountAsync();
   backend_->UpdateTotalAlbumCountAsync();
 
-  connect(app_, SIGNAL(ClearPixmapDiskCache()), SLOT(ClearDiskCache()));
-
   ReloadSettings();
 
 }
@@ -189,7 +189,9 @@ void CollectionModel::ReloadSettings() {
 
   QPixmapCache::setCacheLimit(MaximumCacheSize(&s, CollectionSettingsPage::kSettingsCacheSize, CollectionSettingsPage::kSettingsCacheSizeUnit, CollectionSettingsPage::kSettingsCacheSizeDefault) / 1024);
 
-  sIconCache->setMaximumCacheSize(MaximumCacheSize(&s, CollectionSettingsPage::kSettingsDiskCacheSize, CollectionSettingsPage::kSettingsDiskCacheSizeUnit, CollectionSettingsPage::kSettingsDiskCacheSizeDefault));
+  if (sIconCache) {
+    sIconCache->setMaximumCacheSize(MaximumCacheSize(&s, CollectionSettingsPage::kSettingsDiskCacheSize, CollectionSettingsPage::kSettingsDiskCacheSizeUnit, CollectionSettingsPage::kSettingsDiskCacheSizeDefault));
+  }
 
   s.endGroup();
 
@@ -510,7 +512,7 @@ void CollectionModel::SongsDeleted(const SongList &son
       // Remove from pixmap cache
       const QString cache_key = AlbumIconPixmapCacheKey(ItemToIndex(node));
       QPixmapCache::remove(cache_key);
-      if (use_disk_cache_) sIconCache->remove(QUrl(cache_key));
+      if (use_disk_cache_ && sIconCache) sIconCache->remove(QUrl(cache_key));
       if (pending_cache_keys_.contains(cache_key)) {
         pending_cache_keys_.remove(cache_key);
       }
@@ -585,7 +587,7 @@ QVariant CollectionModel::AlbumIcon(const QModelIndex 
   }
 
   // Try to load it from the disk cache
-  if (use_disk_cache_) {
+  if (use_disk_cache_ && sIconCache) {
     std::unique_ptr<QIODevice> cache(sIconCache->data(QUrl(cache_key)));
     if (cache) {
       QImage cached_image;
@@ -637,7 +639,7 @@ void CollectionModel::AlbumCoverLoaded(const quint64 i
   }
 
   // If we have a valid cover not already in the disk cache
-  if (use_disk_cache_) {
+  if (use_disk_cache_ && sIconCache) {
     std::unique_ptr<QIODevice> cached_img(sIconCache->data(QUrl(cache_key)));
     if (!cached_img && !result.image_scaled.isNull()) {
       QNetworkCacheMetaData item_metadata;
@@ -1556,6 +1558,7 @@ int CollectionModel::MaximumCacheSize(QSettings *s, co
   } while (unit > 0);
 
   return size;
+
 }
 
 void CollectionModel::GetChildSongs(CollectionItem *item, QList<QUrl> *urls, SongList *songs, QSet<int> *song_ids) const {
@@ -1686,7 +1689,7 @@ void CollectionModel::TotalAlbumCountUpdatedSlot(const
 }
 
 void CollectionModel::ClearDiskCache() {
-  sIconCache->clear();
+  if (sIconCache) sIconCache->clear();
 }
 
 QDataStream &operator<<(QDataStream &s, const CollectionModel::Grouping &g) {
