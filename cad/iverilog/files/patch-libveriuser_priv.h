--- libveriuser/priv.h.orig	2020-08-18 15:47:00 UTC
+++ libveriuser/priv.h
@@ -30,7 +30,8 @@ extern char* __acc_newstring(const char*txt);
 
 /*
  * Trace file for logging ACC and TF calls.
+ * Defined in libveriuser/priv.c
  */
-FILE* pli_trace;
+extern FILE* pli_trace;
 
 #endif /* IVL_priv_H */
