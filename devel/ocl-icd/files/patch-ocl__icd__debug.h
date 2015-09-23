--- ocl_icd_debug.h.orig	2015-08-06 20:54:47 UTC
+++ ocl_icd_debug.h
@@ -61,9 +61,9 @@ extern int debug_ocl_icd_mask;
 	return ret; \
    } while(0)
 #  define RETURN_STR(val) do { \
-	char* ret=(char*)(val);			\
-	debug(D_TRACE, "return: %s", ret);	\
-	return ret; \
+	char* _return_str=(char*)(val);			\
+	debug(D_TRACE, "return: %s", _return_str);	\
+	return _return_str; \
    } while(0)
 #  ifdef DEBUG_OCL_ICD_PROVIDE_DUMP_FIELD
 #    pragma GCC diagnostic push
