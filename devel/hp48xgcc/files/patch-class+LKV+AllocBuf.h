--- class/LKV/AllocBuf.h	3 Nov 2004 06:57:51 -0000	1.1
+++ class/LKV/AllocBuf.h	3 Nov 2004 07:25:07 -0000	1.2
@@ -141,6 +141,6 @@
 #define LAZYSTATIC(CLNAME) \
 AllocBuf CLNAME::ab_static(sizeof(CLNAME),#CLNAME);
 
-#endif NO_LAZY_ALLOC
+#endif /* NO_LAZY_ALLOC */
 
-#endif AllocBuf_h
+#endif /* AllocBuf_h */
