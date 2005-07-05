--- kspread/dialogs/kspread_dlg_database.cc.orig	Tue Jun 28 03:42:22 2005
+++ kspread/dialogs/kspread_dlg_database.cc	Tue Jun 28 03:48:20 2005
@@ -600,8 +600,8 @@
   // An update command must also be followed by a space, or it would be parsed
   // as an identifier.
   // For sanity, also check that there is a SELECT 
-  QRegExp couldModifyDB( "(^|[( \s])(UPDATE|DELETE|INSERT|CREATE) ", false /* cs */ );
-  QRegExp couldQueryDB( "(^|[( \s])(SELECT) ", false /* cs */ );
+  QRegExp couldModifyDB( "(^|[( \\s])(UPDATE|DELETE|INSERT|CREATE) ", false /* cs */ );
+  QRegExp couldQueryDB( "(^|[( \\s])(SELECT) ", false /* cs */ );
 
   if (couldModifyDB.search( queryStr ) != -1 || couldQueryDB.search ( queryStr ) == -1 )
   {
