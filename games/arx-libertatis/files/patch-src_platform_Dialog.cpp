--- src/platform/Dialog.cpp.orig	2021-07-14 00:04:34 UTC
+++ src/platform/Dialog.cpp
@@ -175,7 +175,7 @@ static std::string formatAsHtml(const std::string & te
 				oss << "http://";
 				i += 6;
 			} else if(!link && line.compare(i, 8, "https://", 8) == 0) {
-				oss << "<a href=";
+				oss << "<a href=\"";
 				link_start = oss.tellp(), link = true;
 				oss << "https://";
 				i += 7;
