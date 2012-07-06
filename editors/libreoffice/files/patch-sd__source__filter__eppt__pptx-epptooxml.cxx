--- sd/source/filter/eppt/pptx-epptooxml.cxx.orig	2012-07-05 15:07:26.000000000 +0200
+++ sd/source/filter/eppt/pptx-epptooxml.cxx	2012-07-05 15:07:42.000000000 +0200
@@ -1377,7 +1377,7 @@
 void PowerPointExport::ImplWriteSlide( sal_uInt32 nPageNum, sal_uInt32 nMasterNum, sal_uInt16 /* nMode */,
                                        sal_Bool bHasBackground, Reference< XPropertySet > aXBackgroundPropSet )
 {
-    DBG(printf("write slide: %"SAL_PRIuUINT32"\n----------------\n", nPageNum));
+    DBG(printf("write slide: %" SAL_PRIuUINT32 "\n----------------\n", nPageNum));
 
     // slides list
     if( nPageNum == 0 )
@@ -1466,7 +1466,7 @@
     if( !mbCreateNotes || !ContainsOtherShapeThanPlaceholders( sal_True ) )
     return;
 
-    DBG(printf("write Notes %"SAL_PRIuUINT32"\n----------------\n", nPageNum));
+    DBG(printf("write Notes %" SAL_PRIuUINT32 "\n----------------\n", nPageNum));
 
     FSHelperPtr pFS = openFragmentStreamWithSerializer( OUStringBuffer()
                                                         .appendAscii( "ppt/notesSlides/notesSlide" )
@@ -1575,7 +1575,7 @@
 
 void PowerPointExport::ImplWriteSlideMaster( sal_uInt32 nPageNum, Reference< XPropertySet > aXBackgroundPropSet )
 {
-    DBG(printf("write slide master: %"SAL_PRIuUINT32"\n----------------\n", nPageNum));
+    DBG(printf("write slide master: %" SAL_PRIuUINT32 "\n----------------\n", nPageNum));
 
     // slides list
     if( nPageNum == 0 )
@@ -1669,7 +1669,7 @@
 
 sal_Int32 PowerPointExport::GetLayoutFileId( sal_Int32 nOffset, sal_uInt32 nMasterNum )
 {
-    DBG(printf("GetLayoutFileId offset: %"SAL_PRIdINT32" master: %"SAL_PRIuUINT32"", nOffset, nMasterNum));
+    DBG(printf("GetLayoutFileId offset: %" SAL_PRIdINT32 " master: %" SAL_PRIuUINT32 "", nOffset, nMasterNum));
     if( mLayoutInfo[ nOffset ].mnFileIdArray.size() <= nMasterNum )
         return 0;
 
@@ -1684,7 +1684,7 @@
 
 void PowerPointExport::ImplWritePPTXLayout( sal_Int32 nOffset, sal_uInt32 nMasterNum )
 {
-    DBG(printf("write layout: %"SAL_PRIdINT32"\n", nOffset));
+    DBG(printf("write layout: %" SAL_PRIdINT32 "\n", nOffset));
 
     Reference< drawing::XDrawPagesSupplier > xDPS( getModel(), uno::UNO_QUERY );
     Reference< drawing::XDrawPages > xDrawPages( xDPS->getDrawPages(), uno::UNO_QUERY );
@@ -2272,7 +2272,7 @@
         if( value >>= strValue )
             printf ("\"%s\"\n", USS( strValue ) );
         else if( value >>= intValue )
-            printf ("%"SAL_PRIdINT32"            (hex: %"SAL_PRIxUINT32")\n", intValue, intValue);
+            printf ("%" SAL_PRIdINT32 "            (hex: %" SAL_PRIxUINT32 ")\n", intValue, intValue);
         else if( value >>= boolValue )
             printf ("%d            (bool)\n", boolValue);
         else if( value >>= pointValue )
