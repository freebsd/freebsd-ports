
$FreeBSD$

--- ../handc/runtime/vinsns.h	Fri Feb 10 15:56:41 2006
+++ ../handc/runtime/vinsns.h	Fri Feb 10 15:56:57 2006
@@ -58,7 +58,7 @@
 			       arg_count_reg = num; \
 			       return (jump_addr)label;)
 #else
-#define JUMP(num,label)   return (jump_addr)((jump_addr)label)()
+#define JUMP(num,label)   return label()
 #endif
 #endif
 
--- ../stage0/runtime/vinsns.h	Fri Feb 10 15:56:41 2006
+++ ../stage0/runtime/vinsns.h	Fri Feb 10 15:56:57 2006
@@ -58,7 +58,7 @@
 			       arg_count_reg = num; \
 			       return (jump_addr)label;)
 #else
-#define JUMP(num,label)   return (jump_addr)((jump_addr)label)()
+#define JUMP(num,label)   return label()
 #endif
 #endif
 
