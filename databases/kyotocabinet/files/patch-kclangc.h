--- kclangc.h.orig	2020-12-18 02:48:28 UTC
+++ kclangc.h
@@ -258,14 +258,14 @@ size_t kclevdist(const void* abuf, size_t asiz, const 
  * Get the quiet Not-a-Number value.
  * @return the quiet Not-a-Number value.
  */
-double kcnan();
+double kcnan(void);
 
 
 /**
  * Get the positive infinity value.
  * @return the positive infinity value.
  */
-double kcinf();
+double kcinf(void);
 
 
 /**
@@ -1522,7 +1522,7 @@ typedef struct {
  * @note The object of the return value should be released with the kclistdel function when it is
  * no longer in use.
  */
-KCLIST* kclistnew();
+KCLIST* kclistnew(void);
 
 
 /**
