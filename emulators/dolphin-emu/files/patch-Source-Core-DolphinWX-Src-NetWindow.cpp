--- Source/Core/DolphinWX/Src/NetWindow.cpp.orig	2013-09-18 15:49:16.000000000 +0200
+++ Source/Core/DolphinWX/Src/NetWindow.cpp	2013-09-18 15:52:24.000000000 +0200
@@ -38,7 +38,11 @@
 		name = game.GetVolumeName(lang);
 
 	if (game.GetRevision() != 0)
-		return name + " (" + game.GetUniqueID() + ", Revision " + std::to_string((long long)game.GetRevision()) + ")";
+	{
+		std::stringstream tmp_stream;
+		tmp_stream << game.GetRevision();
+		return name + " (" + game.GetUniqueID() + ", Revision " + tmp_stream.str() + ")";
+	}
 	else
 		return name + " (" + game.GetUniqueID() + ")";
 }
