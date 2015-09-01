--- ./vcl/unx/gtk/gdi/salnativewidgets-gtk.cxx.orig	2013-01-31 05:54:53.000000000 -0500
+++ ./vcl/unx/gtk/gdi/salnativewidgets-gtk.cxx	2013-02-18 18:47:08.000000000 -0500
@@ -4025,7 +4025,7 @@
     aStyleSet.SetPreferredSymbolsStyleName( OUString::createFromAscii( pIconThemeName ) );
     g_free( pIconThemeName );
 
-    aStyleSet.SetToolbarIconSize( STYLE_TOOLBAR_ICONSIZE_LARGE );
+    aStyleSet.SetToolbarIconSize( nDispDPIY > 160 ? STYLE_TOOLBAR_ICONSIZE_LARGE : STYLE_TOOLBAR_ICONSIZE_SMALL );
 
 #if !GTK_CHECK_VERSION(2,9,0)
     static cairo_font_options_t* (*gdk_screen_get_font_options)(GdkScreen*) =
