--- amarok/src/mediadevice/mtp/mtpmediadevice.cpp
+++ amarok/src/mediadevice/mtp/mtpmediadevice.cpp
@@ -293,12 +293,13 @@
         parent_id = getDefaultParentId();
     }
     debug() << "Parent id : " << parent_id << endl;
+    trackmeta->parent_id = parent_id;
 
     m_critical_mutex.lock();
     debug() << "Sending track... " << bundle.url().path().utf8() << endl;
     int ret = LIBMTP_Send_Track_From_File(
         m_device, bundle.url().path().utf8(), trackmeta,
-        progressCallback, this, parent_id
+        progressCallback, this
     );
     m_critical_mutex.unlock();
 
@@ -529,7 +530,7 @@
         for( MtpMediaItem *it = dynamic_cast<MtpMediaItem*>(items->first()); it; it = dynamic_cast<MtpMediaItem*>(items->next()) )
             album_object->tracks[i++] = it->track()->id();
         album_object->no_tracks = items->count();
-        ret = LIBMTP_Create_New_Album( m_device, album_object, 0 );
+        ret = LIBMTP_Create_New_Album( m_device, album_object );
         if( ret != 0 )
         {
             debug() << "creating album failed : " << ret << endl;
@@ -608,7 +609,7 @@
 {
     debug() << "Creating new folder '" << name << "' as a child of "<< parent_id << endl;
     char *name_copy = qstrdup( name );
-    uint32_t new_folder_id = LIBMTP_Create_Folder( m_device, name_copy, parent_id );
+    uint32_t new_folder_id = LIBMTP_Create_Folder( m_device, name_copy, parent_id, 0 );
     delete(name_copy);
     debug() << "New folder ID: " << new_folder_id << endl;
     if( new_folder_id == 0 )
@@ -913,7 +914,7 @@
     if( item->playlist()->id() == 0 )
     {
         debug() << "creating new playlist : " << metadata->name << endl;
-        int ret = LIBMTP_Create_New_Playlist( m_device, metadata, 0 );
+        int ret = LIBMTP_Create_New_Playlist( m_device, metadata );
         if( ret == 0 )
         {
             item->playlist()->setId( metadata->playlist_id );
