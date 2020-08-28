diff --git a/src/main/workqueue.h b/src/main/workqueue.h
index d5093a533..2af257a45 100644
--- source/mupen64plus-core/src/main/workqueue.h
+++ source/mupen64plus-core/src/main/workqueue.h
@@ -27,7 +27,6 @@
 
 struct work_struct;
 
-struct work_struct *work;
 typedef void (*work_func_t)(struct work_struct *work);
 struct work_struct {
     work_func_t func;
