--- pgadmin/include/pgAdmin3.h.orig	2023-05-22 02:40:57 UTC
+++ pgadmin/include/pgAdmin3.h
@@ -60,8 +60,8 @@
 const short SERVER_MIN_VERSION_N = 0x0804;
 const wxString SERVER_MIN_VERSION_T = wxT("8.4");
 /*ABDUL:BEGIN*/
-const short SERVER_MAX_VERSION_N = 0x0FFF;
-const wxString SERVER_MAX_VERSION_T = wxT("15.255");
+const short SERVER_MAX_VERSION_N = 0x7FFF; /* Don't check for maximally supported PG version. */
+const wxString SERVER_MAX_VERSION_T = wxT("99");
 /*ABDUL:END*/
 
 // Supported Greenplum Database and Greenplum HAWQ minimum and maximum values.
