--- contrib/mod_wrap2_file.c.orig	2007-08-03 06:52:06.000000000 -0800
+++ contrib/mod_wrap2_file.c	2008-03-03 12:33:19.000000000 -0900
@@ -2,7 +2,7 @@
  * ProFTPD: mod_wrap2_file -- a mod_wrap2 sub-module for supplying IP-based
  *                            access control data via file-based tables
  *
- * Copyright (c) 2002-2007 TJ Saunders
+ * Copyright (c) 2002-2008 TJ Saunders
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
@@ -22,12 +22,12 @@
  * with OpenSSL, and distribute the resulting executable, without including
  * the source code for OpenSSL in the source distribution.
  *
- * $Id: mod_wrap2_file.c,v 1.4 2007/08/03 14:52:06 castaglia Exp $
+ * $Id: mod_wrap2_file.c,v 1.6 2008/03/03 16:26:28 castaglia Exp $
  */
 
 #include "mod_wrap2.h"
 
-#define MOD_WRAP2_FILE_VERSION		"mod_wrap2_file/1.1"
+#define MOD_WRAP2_FILE_VERSION		"mod_wrap2_file/1.2"
 
 static const char *filetab_service_name = NULL;
 
@@ -74,7 +74,9 @@
     service = pstrndup(filetab->tab_pool, buf, (res - buf));
 
     if (filetab_service_name &&
-        strcasecmp(filetab_service_name, service) == 0) {
+        (strcasecmp(filetab_service_name, service) == 0 ||
+         strcasecmp("ALL", service) == 0)) {
+      char *tmp = NULL;
 
       if (filetab_daemons_list == NULL)
         filetab_daemons_list = make_array(filetab->tab_pool, 0, sizeof(char *));
@@ -91,9 +93,31 @@
       if (filetab_clients_list == NULL)
         filetab_clients_list = make_array(filetab->tab_pool, 0, sizeof(char *));
 
-      *((char **) push_array(filetab_clients_list)) =
-        pstrdup(filetab->tab_pool, res);
-    
+      /* If there are commas in the line, parse them as separate client
+       * names.  Otherwise, a comma-delimited list of names will be treated
+       * as a single name, and violate the principal of least surprise
+       * for the site admin.
+       */
+      tmp = strchr(res, ',');
+      if (tmp != NULL) {
+        char *dup = pstrdup(filetab->tab_pool, res);
+        char *word;
+
+        while ((word = pr_str_get_word(&dup, 0)) != NULL) {
+          size_t wordlen = strlen(word);
+
+          /* Remove any trailing comma */
+          if (word[wordlen-1] == ',')
+            word[wordlen-1] = '\0';
+
+          *((char **) push_array(filetab_clients_list)) = word;
+        }
+
+      } else {
+        *((char **) push_array(filetab_clients_list)) =
+          pstrdup(filetab->tab_pool, res);
+      }
+ 
       res = wrap2_strsplit(res, ':');    
       if (res) {
         if (filetab_options_list == NULL)
