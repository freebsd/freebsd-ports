--- mysql-gui-common/library/source/myx_library.c.orig	Sat Mar 20 21:58:39 2004
+++ mysql-gui-common/library/source/myx_library.c	Sat Mar 20 22:12:51 2004
@@ -35,6 +35,7 @@
 #endif
 typedef long long longlong;
 typedef unsigned long long ulonglong;
+typedef int	pchar;
 #else
 typedef unsigned int           uint;   
 typedef unsigned char           uint8;
@@ -306,7 +307,7 @@
   machine_info->IP= malloc(sizeof(char)*16);
   machine_info->OS= malloc(sizeof(char)*16);
   machine_info->hardware= malloc(sizeof(char)*200);
-
+/*
   if(mysql->options.protocol==MYSQL_PROTOCOL_MEMORY)
   {
     add_host_info= strdup("via shared memory");
@@ -320,14 +321,14 @@
     add_host_info= strdup("via named pipe");  
   }
   else if(mysql->options.protocol==MYSQL_PROTOCOL_TCP)
-  {
+  {*/
     add_host_info= strdup("via TCP/IP");
-  }
+/*  }
   else
   {
     add_host_info= strdup("");
   }
-
+*/
   sprintf(machine_info->version, "MySQL %s %s", (unsigned char *)mysql_get_server_info(mysql), add_host_info);
 
   free(add_host_info);
@@ -482,7 +483,7 @@
 
 const char * myx_get_server_charset_name(MYSQL *mysql)
 {
-  return mysql->charset->csname;
+  return mysql->charset->name;
 }
 
 
