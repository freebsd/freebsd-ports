--- kbarcode/labeleditor.cpp.orig	Tue Jul 20 05:57:28 2004
+++ kbarcode/labeleditor.cpp	Mon Aug 23 17:25:56 2004
@@ -552,7 +552,7 @@
     exportZPLAct = new KAction( i18n("...as &IPL or ZPL"), 0, 0, this, SLOT(exportZPL() ), actionCollection() );
     descriptionAct = new KAction( i18n("&Change description..."), 0, 0, this, SLOT(changeDes()), actionCollection() );
     deleteAct = new KAction( i18n("&Delete Object"), QIconSet( BarIcon("editdelete") ), Key_Delete, cv, SLOT( deleteCurrent() ), actionCollection() );
-    editPropAct = new KAction( i18n("&Properties..."), 0, 0, this, SLOT(), actionCollection() );
+    editPropAct = new KAction( i18n("&Properties..."), 0, 0, this, SLOT( doubleClickedCurrent() ), actionCollection() );
     printAct = KStdAction::print( this, SLOT( print() ), actionCollection(), "print" );
     changeSizeAct = new KAction( i18n("&Change Label..."), 0, 0, this, SLOT( changeSize() ), actionCollection() );
     barcodeAct = new KAction( i18n("Insert &Barcode"), QIconSet( BarIcon("barcode") ), 0, this, SLOT( insertBarcode() ), actionCollection() );
