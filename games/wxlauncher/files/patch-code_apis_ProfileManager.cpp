--- code/apis/ProfileManager.cpp.orig	2015-01-28 04:29:37 UTC
+++ code/apis/ProfileManager.cpp
@@ -307,7 +307,7 @@ void ProMan::LoadNewsMapFromGlobalProfil
 		if (globalProfile->Read(GBL_CFG_NET_THE_NEWS, &theNews) &&
 			(globalProfile->Read(GBL_CFG_NET_NEWS_LAST_TIME, &lastDownloadNewsStr))) {
 			if ((!theNews.IsEmpty()) &&
-				(NULL != lastDownloadNews.ParseFormat(
+				(0 != lastDownloadNews.ParseFormat(
 					lastDownloadNewsStr, NEWS_LAST_TIME_FORMAT))) {
 				newsMap[groupName] = NewsData(theNews, lastDownloadNews);
 				
