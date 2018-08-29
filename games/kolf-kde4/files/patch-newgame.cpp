--- newgame.cpp.orig	2018-08-29 20:35:41 UTC
+++ newgame.cpp
@@ -285,7 +285,7 @@ void NewGameDialog::addCourse()
 
 	for (QStringList::const_iterator fileIt = files.begin(); fileIt != files.end(); ++fileIt)
 	{
-		if (names.contains(*fileIt) > 0)
+		if (bool(names.contains(*fileIt)))
 		{
 			hasDuplicates = true;
 			continue;
