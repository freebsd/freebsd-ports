--- IndexSearch/PluginWebEngine.cpp.orig	2012-04-08 10:39:34.000000000 +0200
+++ IndexSearch/PluginWebEngine.cpp	2013-03-10 17:09:52.000000000 +0100
@@ -165,14 +165,12 @@
 	}
 
 	string extension(fileName.substr(pos + 1));
-#ifdef HAVE_BOOST_SPIRIT_CORE_HPP
 	if (strncasecmp(extension.c_str(), "src", 3) == 0)
 	{
 		pluginType = "sherlock";
 		return new SherlockParser(fileName);
 	}
 	else
-#endif
 	if (strncasecmp(extension.c_str(), "xml", 3) == 0)
 	{
 		pluginType = "opensearch";
