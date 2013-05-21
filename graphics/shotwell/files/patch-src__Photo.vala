--- src/Photo.vala.orig
+++ src/Photo.vala
@@ -273,7 +273,7 @@
         }
     }
     
-    private struct BackingReaders {
+    private class BackingReaders {
         public PhotoFileReader master;
         public PhotoFileReader developer;
         public PhotoFileReader editable;
@@ -281,9 +281,9 @@
     
     // because fetching individual items from the database is high-overhead, store all of
     // the photo row in memory
-    private PhotoRow row;
+    protected PhotoRow row;
     private BackingPhotoRow editable = new BackingPhotoRow();
-    private BackingReaders readers = BackingReaders();
+    private BackingReaders readers = new BackingReaders();
     private PixelTransformer transformer = null;
     private PixelTransformationBundle adjustments = null;
     // because file_title is determined by data in row, it should only be accessed when row is locked
@@ -301,7 +301,7 @@
     
     // This pointer is used to determine which BackingPhotoRow in the PhotoRow to be using at
     // any time.  It should only be accessed -- read or write -- when row is locked.
-    private BackingPhotoRow? backing_photo_row = null;
+    protected BackingPhotoRow? backing_photo_row = null;
     
     // This is fired when the photo's editable file is replaced.  The image it generates may or
     // may not be the same; the altered signal is best for that.  null is passed if the editable
@@ -553,8 +553,7 @@
         File file = File.new_for_path(bpr.filepath);
         FileInfo info = file.query_info(DirectoryMonitor.SUPPLIED_ATTRIBUTES,
             FileQueryInfoFlags.NOFOLLOW_SYMLINKS, null);
-        TimeVal timestamp;
-        info.get_modification_time(out timestamp);
+        TimeVal timestamp = info.get_modification_time();
         
         PhotoFileInterrogator interrogator = new PhotoFileInterrogator(
             file, PhotoFileSniffer.Options.GET_ALL);
@@ -992,8 +991,7 @@
             return ImportResult.UNSUPPORTED_FORMAT;
         }
         
-        TimeVal timestamp;
-        info.get_modification_time(out timestamp);
+        TimeVal timestamp = info.get_modification_time();
         
         // if all MD5s supplied, don't sniff for them
         if (params.exif_md5 != null && params.thumbnail_md5 != null && params.full_md5 != null)
@@ -1148,8 +1146,7 @@
             return null;
         }
         
-        TimeVal modification_time = TimeVal();
-        info.get_modification_time(out modification_time);
+        TimeVal modification_time = info.get_modification_time();
         
         backing.filepath = file.get_path();
         backing.timestamp = modification_time.tv_sec;
@@ -1196,7 +1193,7 @@
     }
     
     private class ReimportRawDevelopmentStateImpl : ReimportRawDevelopmentState {
-        class DevToReimport {
+        public class DevToReimport {
             public BackingPhotoRow backing = new BackingPhotoRow();
             public PhotoMetadata? metadata;
             
@@ -1483,8 +1480,7 @@
     
     // Use this only if the master file's modification time has been changed (i.e. touched)
     public void set_master_timestamp(FileInfo info) {
-        TimeVal modification;
-        info.get_modification_time(out modification);
+        TimeVal modification = info.get_modification_time();
         
         try {
             lock (row) {
@@ -1508,8 +1504,7 @@
     
     // Use this only if the editable file's modification time has been changed (i.e. touched)
     public void update_editable_modification_time(FileInfo info) throws DatabaseError {
-        TimeVal modification;
-        info.get_modification_time(out modification);
+        TimeVal modification = info.get_modification_time();
         
         bool altered = false;
         lock (row) {
@@ -2067,8 +2062,7 @@
             error("Unable to read file information for %s: %s", to_string(), err.message);
         }
         
-        TimeVal timestamp = TimeVal();
-        info.get_modification_time(out timestamp);
+        TimeVal timestamp = info.get_modification_time();
         
         // interrogate file for photo information
         PhotoFileInterrogator interrogator = new PhotoFileInterrogator(file);
@@ -2679,7 +2673,7 @@
     }
 
     // All instances are against the coordinate system of the unrotated photo.
-    private void add_raw_redeye_instance(RedeyeInstance redeye) {
+    public void add_raw_redeye_instance(RedeyeInstance redeye) {
         KeyValueMap map = get_transformation("redeye");
         if (map == null) {
             map = new KeyValueMap("redeye");
@@ -3443,8 +3437,7 @@
                 return;
             }
             
-            TimeVal timestamp;
-            info.get_modification_time(out timestamp);
+            TimeVal timestamp = info.get_modification_time();
         
             BackingPhotoTable.get_instance().update_attributes(editable_id, timestamp.tv_sec,
                 info.get_size());
@@ -4567,7 +4560,7 @@
         import_keywords = null;
     }
     
-    protected override void notify_altered(Alteration alteration) {
+    public override void notify_altered(Alteration alteration) {
         // generate new thumbnails in the background
         if (!block_thumbnail_generation && alteration.has_subject("image"))
             thumbnail_scheduler.at_priority_idle(Priority.LOW);
