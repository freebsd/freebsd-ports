Index: qemu/exec-all.h
@@ -30,7 +30,7 @@
 struct TranslationBlock;
 
 /* XXX: make safe guess about sizes */
-#define MAX_OP_PER_INSTR 64
+#define MAX_OP_PER_INSTR 128 /* 64 */
 /* A Call op needs up to 6 + 2N parameters (N = number of arguments).  */
 #define MAX_OPC_PARAM 10
 #define OPC_BUF_SIZE 512
