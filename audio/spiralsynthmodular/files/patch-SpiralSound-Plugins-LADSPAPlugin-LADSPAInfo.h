--- SpiralSound/Plugins/LADSPAPlugin/LADSPAInfo.h.orig	2014-02-13 05:56:16.387137838 +0400
+++ SpiralSound/Plugins/LADSPAPlugin/LADSPAInfo.h	2014-02-13 05:57:44.261183646 +0400
@@ -91,7 +91,7 @@
 		unsigned long   UniqueID;
 		std::string     Name;
 
-		bool operator<(const PluginEntry& pe)
+		bool operator<(const PluginEntry& pe) const
 		{
 			return (Name<pe.Name);
 		}
