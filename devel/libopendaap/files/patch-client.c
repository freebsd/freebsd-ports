--- client.c.orig	Thu May 12 15:46:29 2005
+++ client.c	Mon May 16 19:20:04 2005
@@ -1380,10 +1380,10 @@
 
     HTTP_Connection *http_connection;
 
-    if (strlen(songformat) > 4) return -1;
-
     HTTP_GetResult *httpRes;
 
+    if (strlen(songformat) > 4) return -1;
+
     if (pCHThis->version_major != 3)
     {
         buf = safe_sprintf(songUrl_42, databaseid, songid, songformat,
@@ -1643,10 +1643,11 @@
 static void AsyncWaitUpdate(void *pv_pCHThis, void *unused)
 {
     DAAP_SClientHost *pCHThis = (DAAP_SClientHost*)pv_pCHThis;
-    TRACE("()\n");
     char hash[33] = {0};
     char updateUrl[] = "/update?session-id=%i&revision-number=%i&delta=%i";
     char *buf;
+
+    TRACE("()\n");
 
     buf = safe_sprintf(updateUrl, pCHThis->sessionid, pCHThis->revision_number,
                        pCHThis->revision_number);
