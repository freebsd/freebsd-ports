From 411ef45d8fbda079d51abeba997017e9508fa7a7 Mon Sep 17 00:00:00 2001
From: Colin Clark <cclark@mcb.net>
Date: Tue, 29 Mar 2016 18:18:05 +0100
Subject: [PATCH 1/1] Update for new cogl version

Parameters for cogl_texture_3d_new_from_data have changed.

--- src/renderer-clutter.c.orig	2016-03-07 10:21:06 UTC
+++ src/renderer-clutter.c
@@ -234,7 +234,19 @@ static void rc_prepare_post_process_lut(
 	g_object_unref(tmp_pixbuf);
 
 	DEBUG_0("%s clut upload start", get_exec_time());
-#if CLUTTER_CHECK_VERSION(1,10,0)
+#if COGL_VERSION_CHECK(1,18,2)
+	{
+	CoglContext *ctx = clutter_backend_get_cogl_context(clutter_get_default_backend ());
+
+	tex3d = cogl_texture_3d_new_from_data(ctx,
+					      CLUT_SIZE, CLUT_SIZE, CLUT_SIZE,
+					      COGL_PIXEL_FORMAT_RGB_888,
+					      CLUT_SIZE * 3,
+					      CLUT_SIZE * CLUT_SIZE * 3,
+					      clut,
+					      NULL);
+	}
+#elif COGL_VERSION_CHECK(1,10,4)
 	{
 	CoglContext *ctx = clutter_backend_get_cogl_context(clutter_get_default_backend ());
 
