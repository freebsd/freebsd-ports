$NetBSD: patch-libmedia_FLVParser.cpp,v 1.1 2013/08/31 14:52:14 joerg Exp $

--- libmedia/FLVParser.cpp.orig	2013-08-31 11:58:57.000000000 +0000
+++ libmedia/FLVParser.cpp
@@ -447,7 +447,7 @@ FLVParser::parseNextTag(bool index_only)
 		}
 
 		boost::mutex::scoped_lock lock(_metaTagsMutex);
-		_metaTags.insert(std::make_pair(flvtag.timestamp, metaTag.release()));
+		_metaTags.insert(std::make_pair(boost::uint64_t(flvtag.timestamp), boost::shared_ptr<SimpleBuffer>(metaTag.release())));
 	}
 	else
 	{
