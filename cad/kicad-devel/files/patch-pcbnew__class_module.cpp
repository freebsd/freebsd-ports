--- ./pcbnew/class_module.cpp.orig	2008-08-09 11:05:42.000000000 +0200
+++ ./pcbnew/class_module.cpp	2008-09-20 22:18:34.000000000 +0200
@@ -1060,7 +1060,7 @@
     pos += 6;
     if( flag ) // Affichage date de modification (utile en Module Editor)
     {
-        strcpy( Line, ctime( &m_LastEdit_Time ) );
+        strcpy( Line, ctime((time_t*) &m_LastEdit_Time ) );
         strtok( Line, " \n\r" );
         strcpy( bufcar, strtok( NULL, " \n\r" ) ); strcat( bufcar, " " );
         strcat( bufcar, strtok( NULL, " \n\r" ) ); strcat( bufcar, ", " );
