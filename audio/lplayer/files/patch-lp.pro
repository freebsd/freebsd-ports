--- lp.pro.orig	Wed Nov 13 05:39:16 2002
+++ lp.pro	Mon Dec 16 06:31:17 2002
@@ -82,9 +82,8 @@
 #Qt only
 #==============================================================================
 #works most of the time
-TMAKE_LIBS      = -lxmms -L/sw/lib -lglib
-INCLUDEPATH     = /usr/include/xmms /usr/lib/glib/include /usr/include/glib-1.2\
-				/sw/include/xmms /sw/lib/glib/include /sw/include/glib-1.2
+TMAKE_LIBS      = -L@X11BASE@/lib -L@LOCALBASE@/lib @XMMSLIBS@
+INCLUDEPATH     = @X11BASE@/include @X11BASE@/include @XMMSINCS@
 
 #mac os x using fink
 #TMAKE_LIBS      = -lxmms -L/sw/lib -lglib
