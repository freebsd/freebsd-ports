--- ./kspread/kspread_dlg_preference.cc.orig	Mon Jul 29 09:24:21 2002
+++ ./kspread/kspread_dlg_preference.cc	Sun Nov 17 06:31:59 2002
@@ -719,7 +719,7 @@
   QLabel *label = new QLabel(i18n("&Grid color:"), tmpQGroupBox,"label20" );
 
   gridColor = new KColorButton( _gridColor,
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
                                 Qt::lightGray,
 #endif
                                 tmpQGroupBox );
@@ -736,7 +736,7 @@
   QLabel * label2 = new QLabel( i18n("&Page borders:"), tmpQGroupBox, "label21" );
 
   pageBorderColor = new KColorButton( _pbColor,
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
                                 Qt::red,
 #endif
                                 tmpQGroupBox );
