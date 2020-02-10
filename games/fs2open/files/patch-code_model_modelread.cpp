--- code/model/modelread.cpp.orig	2020-02-10 13:38:06 UTC
+++ code/model/modelread.cpp
@@ -5341,7 +5341,7 @@ void swap_bsp_sortnorms( polymodel * pm, ubyte * p )
 }
 #endif // BIG_ENDIAN
 
-void swap_bsp_data( polymodel *  /*pm*/, void * /*model_ptr*/ )
+void swap_bsp_data( polymodel *pm, void *model_ptr )
 {
 #if BYTE_ORDER == BIG_ENDIAN
 	ubyte *p = (ubyte *)model_ptr;
@@ -5397,7 +5397,7 @@ void swap_bsp_data( polymodel *  /*pm*/, void * /*mode
 #endif
 }
 
-void swap_sldc_data(ubyte * /*buffer*/)
+void swap_sldc_data(ubyte * buffer)
 {
 #if BYTE_ORDER == BIG_ENDIAN
 	char *type_p = (char *)(buffer);
