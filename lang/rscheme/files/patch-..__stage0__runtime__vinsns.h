
$FreeBSD: /tmp/pcvs/ports/lang/rscheme/files/patch-..__stage0__runtime__vinsns.h,v 1.1 2006-04-20 21:32:20 anray Exp $

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
 
