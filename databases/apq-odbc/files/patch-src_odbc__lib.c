--- src/odbc_lib.c.orig	2012-01-10 14:17:05.000000000 -0500
+++ src/odbc_lib.c
@@ -1,3 +1,5 @@
+#include <stdlib.h>
+#include <string.h>
 #include "odbc_lib.h"
 
 
@@ -43,10 +45,10 @@ void login_Information_Set_Up (ODBC_Logi
 
 int get_Login_String_Size (ODBC_Login_Information* login_Information) {
 
+  int total_Size = 0;
   if (!is_Ready(login_Information))
     return(-1);
 
-  int total_Size = 0;
   total_Size += strlen(login_Information->p_Formatted_User_Name);
   total_Size += strlen(login_Information->p_Formatted_Password);
   total_Size += strlen(login_Information->p_Formatted_Data_Source);
@@ -75,6 +77,7 @@ int print_Login_String (ODBC_Login_Infor
   strcat(destiny, login_Information->p_Formatted_User_Name);
   strcat(destiny, login_Information->p_Formatted_Password);
   strcat(destiny, login_Information->p_Formatted_Data_Source);
+  return(0);
 }
 
 void reset_Login_Information (ODBC_Login_Information* login_Information) {
@@ -241,7 +244,7 @@ void connect_With_Data_Source (ODBC_Faca
 		     + 1);
 
   if (SQL_SUCCEEDED(SQLDriverConnect(odbc_Facade->connection_Handle, NULL,
-				     login_String, SQL_NTS, NULL, 0, NULL,
+                           (SQLCHAR*)login_String, SQL_NTS, NULL, 0, NULL,
 				     SQL_DRIVER_NOPROMPT)))
     switch_On_Connection(odbc_Facade);
 
@@ -273,14 +276,14 @@ ODBC_Query_Results* create_And_Run_SQL_S
 //TODO: Return error string instead of printing it?
 void p_Print_Error_Information (ODBC_Facade* odbc_Facade) {
 
-  char ercode[6];
+  SQLCHAR     ercode[6];
   SQLINTEGER  err;
-  char error[250];
+  SQLCHAR     error[250];
   SQLSMALLINT size;
 
   SQLGetDiagRec(SQL_HANDLE_DBC, odbc_Facade->environment_Handle, 1, ercode,
 		&err, error, 250, &size);
-  printf ("\n%d, %s - %s\n", err, ercode, error);
+  printf ("\n%d, %s - %s\n", (int)err, ercode, error);
 }
 
 
@@ -289,4 +292,5 @@ void p_Print_Error_Information (ODBC_Fac
 char* alloc_String (int size) {
   char* return_Value = malloc(sizeof(char) * size);
   *return_Value = '\0';
+  return return_Value;
 }
