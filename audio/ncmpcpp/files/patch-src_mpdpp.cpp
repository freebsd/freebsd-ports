--- src/mpdpp.cpp.orig	2016-04-17 05:41:01 UTC
+++ src/mpdpp.cpp
@@ -105,6 +105,8 @@ Connection::Connection() : m_connection(
 				m_port(6600),
 				m_timeout(15)
 {
+	std::random_device rd;
+	m_gen.seed(rd());
 }
 
 void Connection::Connect()
@@ -570,7 +572,7 @@ bool Connection::AddRandomTag(mpd_tag_ty
 	if (number > tags.size())
 		return false;
 
-	std::random_shuffle(tags.begin(), tags.end());
+	std::shuffle(tags.begin(), tags.end(), m_gen);
 	auto it = tags.begin();
 	for (size_t i = 0; i < number && it != tags.end(); ++i)
 	{
@@ -609,7 +611,7 @@ bool Connection::AddRandomSongs(size_t n
 	}
 	else
 	{
-		std::random_shuffle(files.begin(), files.end());
+		std::shuffle(files.begin(), files.end(), m_gen);
 		StartCommandsList();
 		auto it = files.begin();
 		for (size_t i = 0; i < number && it != files.end(); ++i, ++it)
