--- ./inc/preferencesdialog.hpp.orig	2012-01-30 01:27:51.000000000 +0100
+++ ./inc/preferencesdialog.hpp	2014-07-24 13:12:17.000000000 +0200
@@ -198,7 +198,7 @@
 	protected:
 		struct LangCompare
 		{
-			bool operator()(GtkSourceLanguage* first, GtkSourceLanguage* second)
+			bool operator()(const GtkSourceLanguage* first, const GtkSourceLanguage* second) const
 			{
 				return first < second;
 			}
