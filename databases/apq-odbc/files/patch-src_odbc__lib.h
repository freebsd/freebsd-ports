--- src/odbc_lib.h.orig	2012-01-10 14:17:05.000000000 -0500
+++ src/odbc_lib.h
@@ -43,7 +43,7 @@ struct odbc_login_information {
 };
 
 //Public methods for ODBC_Login_Information.
-ODBC_Login_Information* new_ODBC_Login_Information ();
+ODBC_Login_Information* new_ODBC_Login_Information (void);
 
 void set_User_Name (ODBC_Login_Information* login_Information,
 		    char* new_User_Name);
@@ -126,7 +126,7 @@ struct odbc_facade {
   ODBC_Login_Information* login_Information;
 };
 
-ODBC_Facade* new_ODBC_Facade ();
+ODBC_Facade* new_ODBC_Facade (void);
 
 void set_Up_Environment_Handle (ODBC_Facade* odbc_Facade);
 
