--- ./lib/kotext/koParagDia.cc.orig	Sun Sep  1 14:09:03 2002
+++ ./lib/kotext/koParagDia.cc	Sun Nov 17 06:33:53 2002
@@ -1132,7 +1132,7 @@
     grid->addWidget( lColor, 4, 0 );
 
     bColor = new KColorButton( black,
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
                                 black,
 #endif
                                 this );
@@ -1955,7 +1955,7 @@
     QLabel *lcolor = new QLabel( i18n( "Color:" ), shadow );
     grid2->addWidget(lcolor,0,0);
     color = new KColorButton( black,
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
                               black,
 #endif
                               shadow );
