--- code/model/modelread.cpp.orig	2020-01-25 16:45:09 UTC
+++ code/model/modelread.cpp
@@ -5341,7 +5341,7 @@ void swap_bsp_sortnorms( polymodel * pm, ubyte * p )
 }
 #endif // BIG_ENDIAN
 
-void swap_bsp_data( polymodel *  /*pm*/, void * /*model_ptr*/ )
+void swap_bsp_data( polymodel *pm, void *model_ptr )
 {
 #if BYTE_ORDER == BIG_ENDIAN
 	ubyte *p = (ubyte *)model_ptr;
@@ -5394,10 +5394,13 @@ void swap_bsp_data( polymodel *  /*pm*/, void * /*mode
 	}
 
 	return;
+#else
+(void)pm;
+(void)model_ptr;
 #endif
 }
 
-void swap_sldc_data(ubyte * /*buffer*/)
+void swap_sldc_data(ubyte * buffer)
 {
 #if BYTE_ORDER == BIG_ENDIAN
 	char *type_p = (char *)(buffer);
@@ -5439,6 +5442,8 @@ void swap_sldc_data(ubyte * /*buffer*/)
 			shld_polys[i] = INTEL_INT(shld_polys[i]);
 		}			
 	}
+#else
+(void)buffer;
 #endif
 }
 
