--- src/PlaylistEditDialogData.cpp.orig	Mon Nov 19 11:41:19 2001
+++ src/PlaylistEditDialogData.cpp	Sat Aug 24 19:41:01 2002
@@ -151,8 +151,6 @@
 
     subtuneSpinBox = new QSpinBox( this, "subtuneSpinBox" );
     subtuneSpinBox->setGeometry( QRect( 260, 115, 50, 25 ) ); 
-    subtuneSpinBox->setFrameShape( QSpinBox::WinPanel );
-    subtuneSpinBox->setFrameShadow( QSpinBox::Sunken );
     subtuneSpinBox->setButtonSymbols( QSpinBox::PlusMinus );
     subtuneSpinBox->setMaxValue( 256 );
     subtuneSpinBox->setMinValue( 1 );
