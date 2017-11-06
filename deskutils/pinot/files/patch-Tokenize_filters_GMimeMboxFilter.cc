--- Tokenize/filters/GMimeMboxFilter.cc.orig	2017-04-03 09:38:48 UTC
+++ Tokenize/filters/GMimeMboxFilter.cc
@@ -301,7 +301,7 @@ bool GMimeMboxFilter::skip_to_document(const string &i
 	}
 
 	// ipath's format is "o=offset&l=part_levels"
-	if (sscanf(ipath.c_str(), "o="GMIME_OFFSET_MODIFIER"&l=[", &m_messageStart) != 1)
+	if (sscanf(ipath.c_str(), "o=" GMIME_OFFSET_MODIFIER "&l=[", &m_messageStart) != 1)
 	{
 		return false;
 	}
