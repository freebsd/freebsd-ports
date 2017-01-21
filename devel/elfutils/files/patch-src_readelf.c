--- src/readelf.c.orig	2016-12-28 09:32:01 UTC
+++ src/readelf.c
@@ -8037,6 +8037,7 @@ print_debug_exception_table (Dwfl_Module
 	default:
 	  dsize = 0;
 	  error (1, 0, gettext ("invalid TType encoding"));
+	  abort();
 	}
 
       if (max_ar_filter
