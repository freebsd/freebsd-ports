--- ./kpresenter/kpresenter_dlg_config.cc.orig	Sat Aug 31 07:13:35 2002
+++ ./kpresenter/kpresenter_dlg_config.cc	Sun Nov 17 06:30:28 2002
@@ -305,7 +305,7 @@
     grid1->addWidget( lab, 0, 0 );
 
     bgColor = new KColorButton( oldBgColor,
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
                                 oldBgColor,
 #endif
                                 tmpQGroupBox );
@@ -318,7 +318,7 @@
     grid1->addWidget( lab, 2, 0 );
 
     gridColor = new KColorButton( oldGridColor,
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
                                   oldGridColor,
 #endif
                                   tmpQGroupBox );
