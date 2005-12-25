--- ./pcbnew/class_module.cpp.orig	Mon Dec  5 09:47:56 2005
+++ ./pcbnew/class_module.cpp	Sun Dec 25 16:55:30 2005
@@ -1020,7 +1020,7 @@
 	pos += 14;
 	if ( flag )	// Affichage date de modification (utile en Module Editor)
 	{
-		strcpy(Line, ctime(&m_LastEdit_Time));
+		strcpy(Line, ctime((time_t*) &m_LastEdit_Time));
 		strtok(Line," \n\r");
 		strcpy( bufcar, strtok(NULL," \n\r") ); strcat(bufcar," ");
 		strcat( bufcar, strtok(NULL," \n\r") ); strcat(bufcar,", ");
