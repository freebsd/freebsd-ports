--- src/game/Highscores.cpp.orig	2016-01-04 20:15:21 UTC
+++ src/game/Highscores.cpp
@@ -105,7 +105,7 @@ bool Highscores::add(HighscoresEntry entry) {
 		ofile.close();
 
 		boost::filesystem::copy_file(hsTempFile, hsFile, 
-				boost::filesystem::copy_option::overwrite_if_exists);
+				boost::filesystem::copy_options::overwrite_existing);
 		boost::filesystem::remove(hsTempFile);
 
 		cout << "Scores was updated." << endl;
