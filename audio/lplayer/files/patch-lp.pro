--- lp.pro.orig	Tue Jan 21 01:57:13 2003
+++ lp.pro	Sat Jun 14 20:08:02 2003
@@ -88,9 +88,8 @@
 #Qt only
 #==============================================================================
 #works most of the time
-TMAKE_LIBS      = -lxmms -L/sw/lib -lglib
-INCLUDEPATH     = /usr/include/xmms /usr/lib/glib/include /usr/include/glib-1.2\
-				/sw/include/xmms /sw/lib/glib/include /sw/include/glib-1.2 /sw/include/qt
+TMAKE_LIBS      = -L@X11BASE@/lib -L@LOCALBASE@/lib @XMMSLIBS@
+INCLUDEPATH     = @X11BASE@/include @LOCALBASE@/include @XMMSINCS@
 
 #mac os x using fink
 #TMAKE_LIBS      = -lxmms -L/sw/lib -lglib
