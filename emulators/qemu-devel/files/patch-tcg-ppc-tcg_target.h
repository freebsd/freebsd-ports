--- a/tcg/ppc/tcg-target.h
+++ b/tcg/ppc/tcg-target.h
@@ -69,7 +69,7 @@
 #define TCG_TARGET_CALL_STACK_OFFSET 24
 #elif defined _AIX
 #define TCG_TARGET_CALL_STACK_OFFSET 52
-#elif defined __linux__
+#elif defined __linux__ || defined __FreeBSD__
 #define TCG_TARGET_CALL_ALIGN_ARGS 1
 #define TCG_TARGET_CALL_STACK_OFFSET 8
 #else
