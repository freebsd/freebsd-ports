--- filter/source/graphicfilter/itga/itga.cxx.orig	2014-02-05 10:04:15.000000000 -0500
+++ filter/source/graphicfilter/itga/itga.cxx	2014-02-24 15:38:35.000000000 -0500
@@ -732,8 +732,6 @@
             mpFileHeader->nColorMapEntrySize = 0x3f;    // patch for the following switch routine
         }
         mpColorMap = new sal_uInt32[ nColors ];     // we will always index dwords
-        if ( mpColorMap == sal_False )
-            return sal_False;                       // out of memory %&!$&/!"�$
 
         switch( mpFileHeader->nColorMapEntrySize )
         {
