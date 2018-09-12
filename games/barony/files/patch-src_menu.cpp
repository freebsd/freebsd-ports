--- src/menu.cpp.orig	2018-09-11 19:38:08 UTC
+++ src/menu.cpp
@@ -12266,7 +12266,7 @@ bool gamemodsClearAllMountedPaths()
 	for ( i = PHYSFS_getSearchPath(); *i != NULL; i++ )
 	{
 		std::string line = *i;
-		if ( line.compare(outputdir) != 0 && line.compare("./") != 0 ) // don't unmount the base ./ directory
+		if ( line.compare(outputdir) != 0 && line.compare(datadir) && line.compare("./") != 0 ) // don't unmount the base ./ directory
 		{
 			if ( PHYSFS_unmount(*i) == 0 )
 			{
