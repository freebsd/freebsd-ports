--- Zend/zend_compile.h.orig	2018-02-27 23:15:25 UTC
+++ Zend/zend_compile.h
@@ -414,9 +414,6 @@ struct _zend_execute_data {
 
 #define EX(element) execute_data.element
 
-#define EX_TMP_VAR(ex, n)	   ((temp_variable*)(((char*)(ex)) + ((int)(n))))
-#define EX_TMP_VAR_NUM(ex, n)  (EX_TMP_VAR(ex, 0) - (1 + (n)))
-
 #define EX_CV_NUM(ex, n)       (((zval***)(((char*)(ex))+ZEND_MM_ALIGNED_SIZE(sizeof(zend_execute_data))))+(n))
 
 
