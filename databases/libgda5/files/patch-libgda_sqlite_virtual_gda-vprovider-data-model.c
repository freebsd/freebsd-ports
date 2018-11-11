From d2122f1eb84b9d89596865f663c3e5e355011385 Mon Sep 17 00:00:00 2001
From: Daniel Espinosa <esodan@gmail.com>
Date: Sun, 30 Sep 2018 09:30:34 -0500
Subject: [PATCH] Fix build on MacOS

Thanks to Tom Schoonjans @@tschoonj.

Close issue #142
--- libgda/sqlite/virtual/gda-vprovider-data-model.c.orig	2018-09-27 03:34:56 UTC
+++ libgda/sqlite/virtual/gda-vprovider-data-model.c
@@ -280,7 +280,7 @@ virtual_filtered_data_free (VirtualFilteredData *data)
 static VirtualFilteredData *
 virtual_filtered_data_ref (VirtualFilteredData *data)
 {
-	g_return_if_fail (data != NULL);
+	g_return_val_if_fail (data != NULL, NULL);
 	data->refcount ++;
 	return data;
 }
