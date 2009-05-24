diff --git a/src/lib/playlistmodel.h b/src/lib/playlistmodel.h
index d4f6860..eb54660 100644
--- ./src/lib/playlistmodel.h
+++ ./src/lib/playlistmodel.h
@@ -128,7 +128,11 @@ class PlaylistModel : public QAbstractItemModel
 	private:
 		bool handle_list (const Xmms::List< unsigned int > &list);
 		bool handle_change (const Xmms::Dict &chg);
+#if (XMMS_IPC_PROTOCOL_VERSION > 10)
+		bool handle_update_pos (const Xmms::Dict &pos);
+#else
 		bool handle_update_pos (const unsigned int &pos);
+#endif
 		bool handle_pls_loaded (const std::string &);
         bool handle_current_pls (const std::string &);
 
