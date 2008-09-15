--- src/fio/filemanager.cpp.orig	2008-09-15 16:42:48.000000000 +0000
+++ src/fio/filemanager.cpp	2008-09-15 16:46:08.000000000 +0000
@@ -42,7 +42,7 @@
 
 static guint HashFunc(gconstpointer pKey)
 {
-#ifdef __amd64__
+#if defined __amd64__ || defined __sparc64__ || defined __ia64__
     u_int64_t nKey = (u_int64_t)pKey;
 #else
     u_int32_t nKey = (u_int32_t)pKey;
@@ -85,7 +85,7 @@
     LP_SEARCH_DATA lpData = (LP_SEARCH_DATA)data;
     
     if (strcmp(lpData->pFileName, (const gchar*)value) == 0) {
-#ifdef __amd64__
+#if defined __amd64__ || defined __sparc64__ || defined __ia64__
         lpData->result = (u_int64_t)key;
 #else
         lpData->result = (u_int32_t)key;
