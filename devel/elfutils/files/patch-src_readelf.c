--- src/readelf.c.orig	2020-03-30 12:17:45 UTC
+++ src/readelf.c
@@ -10744,6 +10744,7 @@ print_debug_exception_table (Dwfl_Module *dwflmod __at
 	default:
 	  dsize = 0;
 	  error (1, 0, gettext ("invalid TType encoding"));
+	  abort();
 	}
 
       if (max_ar_filter
