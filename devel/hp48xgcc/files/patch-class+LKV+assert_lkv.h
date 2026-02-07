--- class/LKV/assert_lkv.h	3 Nov 2004 06:57:51 -0000	1.1
+++ class/LKV/assert_lkv.h	3 Nov 2004 07:25:07 -0000	1.2
@@ -5,7 +5,7 @@
 #undef NDEBUG
 #ifndef DEBUG
 	#define NDEBUG
-#endif DEBUG
+#endif /* DEBUG */
 
 #ifdef NDEBUG
 #define assert(_EX)
@@ -20,6 +20,6 @@
 	} \
 }
 
-#endif NDEBUG
+#endif /* NDEBUG */
 
-#endif assert_lkv_h
+#endif /* assert_lkv_h */
