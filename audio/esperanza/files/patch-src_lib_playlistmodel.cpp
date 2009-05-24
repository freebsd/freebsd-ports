diff --git a/src/lib/playlistmodel.cpp b/src/lib/playlistmodel.cpp
index 69a8d46..dab4967 100644
--- ./src/lib/playlistmodel.cpp
+++ ./src/lib/playlistmodel.cpp
@@ -27,6 +27,9 @@
 
 #include "playlistmodel.h"
 
+// Used to check for Protocolversion at compiletime
+#include <xmmsc/xmmsc_idnumbers.h>
+
 PlaylistModel::PlaylistModel (QObject *parent, XClient *client, const QString &name) : QAbstractItemModel (parent)
 {
 //	m_columns.append ("#");
@@ -108,6 +111,19 @@ PlaylistModel::handle_pls_loaded (const std::string &name)
 	return true;
 }
 
+#if (XMMS_IPC_PROTOCOL_VERSION > 10)
+bool
+PlaylistModel::handle_update_pos (const Xmms::Dict &posdict)
+{
+	QString changed_pl = XClient::stdToQ (posdict.get<std::string> ("name"));
+	if (changed_pl == m_name) {
+		uint32_t pos = posdict.get<uint32_t> ("position");
+		m_current_pos = pos;
+		emit dataChanged(index (pos, 0), index (pos, m_columns.size ()));
+	}
+	return true;
+}
+#else
 bool
 PlaylistModel::handle_update_pos (const uint32_t &pos)
 {
@@ -115,6 +131,7 @@ PlaylistModel::handle_update_pos (const uint32_t &pos)
 	emit dataChanged(index (pos, 0), index (pos, m_columns.size ()));
 	return true;
 }
+#endif
 
 QList<QString>
 PlaylistModel::columns () const
