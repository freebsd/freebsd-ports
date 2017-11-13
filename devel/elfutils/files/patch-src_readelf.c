--- src/readelf.c.orig	2017-08-02 12:06:25 UTC
+++ src/readelf.c
@@ -8130,6 +8130,7 @@ print_debug_exception_table (Dwfl_Module
 	default:
 	  dsize = 0;
 	  error (1, 0, gettext ("invalid TType encoding"));
+	  abort();
 	}
 
       if (max_ar_filter
