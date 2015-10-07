--- src/mpdpp.cpp.orig	2015-07-05 02:18:34 UTC
+++ src/mpdpp.cpp
@@ -38,6 +38,8 @@ Connection::Connection() : m_connection(
 				m_port(6600),
 				m_timeout(15)
 {
+	std::random_device rd;
+	m_gen.seed(rd());
 }
 
 Connection::~Connection()
@@ -504,7 +506,7 @@ bool Connection::AddRandomTag(mpd_tag_ty
 	}
 	else
 	{
-		std::random_shuffle(tags.begin(), tags.end());
+		std::shuffle(tags.begin(), tags.end(), m_gen);
 		auto it = tags.begin();
 		for (size_t i = 0; i < number && it != tags.end(); ++i)
 		{
@@ -544,7 +546,7 @@ bool Connection::AddRandomSongs(size_t n
 	}
 	else
 	{
-		std::random_shuffle(files.begin(), files.end());
+		std::shuffle(files.begin(), files.end(), m_gen);
 		StartCommandsList();
 		auto it = files.begin();
 		for (size_t i = 0; i < number && it != files.end(); ++i, ++it)
