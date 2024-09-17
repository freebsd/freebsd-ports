--- Data/include/Poco/Data/LOB.h.orig	2022-10-31 17:44:34 UTC
+++ Data/include/Poco/Data/LOB.h
@@ -63,8 +63,9 @@ class LOB (public)
 	{
 	}
 
-	LOB(const std::basic_string<T>& content):
-		_pContent(new std::vector<T>(content.begin(), content.end()))
+        template <typename TT, typename = std::enable_if_t<std::is_same<TT, char>::value>>
+	LOB(const std::basic_string<TT>& content):
+		_pContent(new std::vector<TT>(content.begin(), content.end()))
 		/// Creates a LOB from a string.
 	{
 	}
