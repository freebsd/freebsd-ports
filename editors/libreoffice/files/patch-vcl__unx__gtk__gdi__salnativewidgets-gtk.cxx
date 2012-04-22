--- ./vcl/unx/gtk/gdi/salnativewidgets-gtk.cxx.orig	2012-03-27 18:22:01.000000000 +0200
+++ ./vcl/unx/gtk/gdi/salnativewidgets-gtk.cxx	2012-04-16 14:24:48.000000000 +0200
@@ -3688,7 +3688,7 @@
     aStyleSet.SetPreferredSymbolsStyleName( OUString::createFromAscii( pIconThemeName ) );
     g_free( pIconThemeName );
 
-    aStyleSet.SetToolbarIconSize( STYLE_TOOLBAR_ICONSIZE_LARGE );
+    aStyleSet.SetToolbarIconSize( nDispDPIY > 160 ? STYLE_TOOLBAR_ICONSIZE_LARGE : STYLE_TOOLBAR_ICONSIZE_SMALL );
 
     const cairo_font_options_t* pNewOptions = NULL;
 #if !GTK_CHECK_VERSION(2,9,0)
