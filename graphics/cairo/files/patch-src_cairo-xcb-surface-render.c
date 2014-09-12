From 18b3cce2f5812c357e4b6310e72d72dd9ec92ed4 Mon Sep 17 00:00:00 2001
From: Bryce Harrington <b.harrington@samsung.com>
Date: Tue, 06 May 2014 17:18:19 +0000
Subject: Fix segfault in firefox when scrolling on certain pages

Bug discovered by thorsten <fly_a320@gmx.de>

Patch from Chris Wilson <chris@chris-wilson.co.uk>
---
diff --git a/src/cairo-xcb-surface-render.c b/src/cairo-xcb-surface-render.c
index 9625953..75455e5 100644
--- src/cairo-xcb-surface-render.c
+++ src/cairo-xcb-surface-render.c
@@ -3121,6 +3121,9 @@ _clip_and_composite_boxes (cairo_xcb_surface_t *dst,
 
 	clip = _cairo_clip_copy (extents->clip);
 	clip = _cairo_clip_intersect_boxes (clip, boxes);
+	if (_cairo_clip_is_all_clipped (clip))
+		return CAIRO_INT_STATUS_NOTHING_TO_DO;
+
 	status = _cairo_clip_get_polygon (clip, &polygon,
 					  &fill_rule, &antialias);
 	_cairo_clip_path_destroy (clip->path);
--
cgit v0.9.0.2-2-gbebe
