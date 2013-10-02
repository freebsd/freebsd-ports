--- src/njamedit.cpp.orig	2008-06-26 22:38:47.000000000 +0000
+++ src/njamedit.cpp
@@ -114,7 +114,7 @@ void NjamEngine::LevelEditor()
 				key = SDLK_a;
 			else if (CheckForSave())
 			{
-				LogFile::LogFile("Saving maps");
+				LogFile("Saving maps");
 				m_Maps.Save(filename);
 				level_type_was = level_type;
 				changed = false;
@@ -139,7 +139,7 @@ void NjamEngine::LevelEditor()
 						"levels/%s.%s",
 #endif					
 						filename, types[level_type]);
-					LogFile::LogFile("Saving maps");
+					LogFile("Saving maps");
 					m_Maps.Save(buf);
 					level_type_was = level_type;
 					changed = false;
