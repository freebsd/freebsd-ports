--- SpiralSound/Plugins/LADSPAPlugin/LADSPAInfo.h.orig	2003-06-05 18:26:42 UTC
+++ SpiralSound/Plugins/LADSPAPlugin/LADSPAInfo.h
@@ -91,7 +91,7 @@ public:
 		unsigned long   UniqueID;
 		std::string     Name;
 
-		bool operator<(const PluginEntry& pe)
+		bool operator<(const PluginEntry& pe) const
 		{
 			return (Name<pe.Name);
 		}
