--- he2/aDictionary.cxx.orig	2001-03-14 09:04:03 UTC
+++ he2/aDictionary.cxx
@@ -128,7 +128,7 @@ aDictionary::findMatchingWords(int accuracyLevel, char
           return 0 ; // nothing to look for
    }
 
-   char **res = new (char *)[result_count_max] ;
+   char **res = new char *[result_count_max] ;
    int *res_dist = new int[result_count_max] ;
    int  last_res= 0 ;
    char *str, **pstr ;
