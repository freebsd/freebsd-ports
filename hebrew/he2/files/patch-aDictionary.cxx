--- aDictionary.cxx.orig	Tue Aug 17 13:50:38 2004
+++ he2/aDictionary.cxx	Tue Aug 17 13:50:52 2004
@@ -128,7 +128,7 @@
           return 0 ; // nothing to look for
    }
 
-   char **res = new (char *)[result_count_max] ;
+   char **res = new char *[result_count_max] ;
    int *res_dist = new int[result_count_max] ;
    int  last_res= 0 ;
    char *str, **pstr ;
