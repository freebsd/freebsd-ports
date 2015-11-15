--- src/mpdpp.cpp.orig	2015-11-09 12:52:27 UTC
+++ src/mpdpp.cpp
@@ -95,6 +95,8 @@ Connection::Connection() : m_connection(
 				m_port(6600),
 				m_timeout(15)
 {
+	std::random_device rd;
+	m_gen.seed(rd());
 }
 
 void Connection::Connect()
@@ -560,7 +562,7 @@ bool Connection::AddRandomTag(mpd_tag_ty
 	if (number > tags.size())
 		return false;
 
-	std::random_shuffle(tags.begin(), tags.end());
+	std::shuffle(tags.begin(), tags.end(), m_gen);
 	auto it = tags.begin();
 	for (size_t i = 0; i < number && it != tags.end(); ++i)
 	{
@@ -599,7 +601,7 @@ bool Connection::AddRandomSongs(size_t n
 	}
 	else
 	{
-		std::random_shuffle(files.begin(), files.end());
+		std::shuffle(files.begin(), files.end(), m_gen);
 		StartCommandsList();
 		auto it = files.begin();
 		for (size_t i = 0; i < number && it != files.end(); ++i, ++it)
