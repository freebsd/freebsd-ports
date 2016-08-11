--- src/readelf.c.orig	2015-06-19 11:17:42 UTC
+++ src/readelf.c
@@ -7911,6 +7911,7 @@ print_debug_exception_table (Dwfl_Module
 	  break;
 	default:
 	  error (1, 0, gettext ("invalid TType encoding"));
+	  abort();
 	}
 
       if (max_ar_filter
