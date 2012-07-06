--- sd/source/filter/eppt/pptx-epptbase.cxx.orig	2012-07-05 15:05:54.000000000 +0200
+++ sd/source/filter/eppt/pptx-epptbase.cxx	2012-07-05 15:06:11.000000000 +0200
@@ -237,7 +237,7 @@
 
     for ( i = 0; i < mnPages; i++ )
     {
-        DBG(printf( "call ImplCreateSlide( %"SAL_PRIuUINT32" )\n", i));
+        DBG(printf( "call ImplCreateSlide( %" SAL_PRIuUINT32 " )\n", i));
         if ( !CreateSlide( i ) )
             return;
     }
@@ -455,7 +455,7 @@
     if ( GetPropertyValue( aAny, rXPropSet, String( RTL_CONSTASCII_USTRINGPARAM( "Layout" ) ) ), sal_True )
         aAny >>= nLayout;
 
-    DBG(printf("GetLayoutOffset %"SAL_PRIdINT32"\n", nLayout));
+    DBG(printf("GetLayoutOffset %" SAL_PRIdINT32 "\n", nLayout));
 
     return nLayout;
 }
@@ -486,7 +486,7 @@
     if( nOffset >= 0 && nOffset < EPP_LAYOUT_SIZE )
         return pPHLayout[ nOffset ];
 
-    DBG(printf("asked %"SAL_PRIdINT32" for layout outside of 0,%d array scope\n", nOffset, EPP_LAYOUT_SIZE ));
+    DBG(printf("asked %" SAL_PRIdINT32 " for layout outside of 0,%d array scope\n", nOffset, EPP_LAYOUT_SIZE ));
 
     return pPHLayout[ 0 ];
 }
