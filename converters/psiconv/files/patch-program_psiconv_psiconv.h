--- program/psiconv/psiconv.h.orig	2020-08-28 22:46:41 UTC
+++ program/psiconv/psiconv.h
@@ -52,7 +52,7 @@ typedef struct fileformat_s {
   output_function *output;
 } *fileformat;
 
-psiconv_list fileformat_list; /* of struct psiconv_fileformat */
+extern psiconv_list fileformat_list; /* of struct psiconv_fileformat */
 
 
 #endif /* PSICONV_H */
