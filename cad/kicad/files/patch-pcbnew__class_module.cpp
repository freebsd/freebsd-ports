--- ./pcbnew/class_module.cpp.orig	Fri Sep  9 12:22:06 2005
+++ ./pcbnew/class_module.cpp	Thu Dec  1 23:15:31 2005
@@ -1017,7 +1017,7 @@
 	pos += 14;
 	if ( flag )	// Affichage date de modification (utile en Module Editor)
 		{
-		strcpy(Line, ctime(&m_LastEdit_Time));
+		strcpy(Line, ctime((time_t*) &m_LastEdit_Time));
 		strtok(Line," \n\r");
 		strcpy( bufcar, strtok(NULL," \n\r") ); strcat(bufcar," ");
 		strcat( bufcar, strtok(NULL," \n\r") ); strcat(bufcar,", ");
