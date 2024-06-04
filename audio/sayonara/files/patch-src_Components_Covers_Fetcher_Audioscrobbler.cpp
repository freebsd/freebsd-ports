--- src/Components/Covers/Fetcher/Audioscrobbler.cpp.orig	2024-06-04 15:10:26 UTC
+++ src/Components/Covers/Fetcher/Audioscrobbler.cpp
@@ -30,6 +30,8 @@
 #include <QStringList>
 #include <QUrl>
 
+#include <array>
+
 using Cover::Fetcher::Audioscrobbler;
 
 namespace
@@ -37,7 +39,7 @@ namespace
 	QStringList mapToStringList(const QMap<QString, QString>& map)
 	{
 		auto result = QStringList {};
-		const auto sizes = std::array {"mega", "extralarge", "large", "medium", "small"};
+		const auto sizes = std::array<char *, 5> {"mega", "extralarge", "large", "medium", "small"};
 		for(const auto size: sizes)
 		{
 			result.push_back(map[size]);
