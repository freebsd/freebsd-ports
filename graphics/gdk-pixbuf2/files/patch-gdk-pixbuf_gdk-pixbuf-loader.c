From 74c418ba2e41ab9e2287420378a6192788b1fab6 Mon Sep 17 00:00:00 2001
From: Sarita Rawat <sarita.rawat@samsung.com>
Date: Fri, 5 Jun 2015 06:56:00 +0000
Subject: Avoid a possible divide-by-zero

Pointed out in

https://bugzilla.gnome.org/show_bug.cgi?id=750440

diff --git a/gdk-pixbuf/gdk-pixbuf-loader.c b/gdk-pixbuf/gdk-pixbuf-loader.c
index 65845ed..668b703 100644
--- gdk-pixbuf/gdk-pixbuf-loader.c
+++ gdk-pixbuf/gdk-pixbuf-loader.c
@@ -330,7 +330,7 @@ gdk_pixbuf_loader_prepare (GdkPixbuf          *pixbuf,
         else
                 anim = gdk_pixbuf_non_anim_new (pixbuf);
   
-	if (priv->needs_scale) {
+	if (priv->needs_scale && width != 0 && height != 0) {
 		priv->animation  = GDK_PIXBUF_ANIMATION (_gdk_pixbuf_scaled_anim_new (anim,
                                          (double) priv->width / width,
                                          (double) priv->height / height,
-- 
cgit v0.10.2

