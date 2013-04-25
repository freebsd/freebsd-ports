--- a/tcg/i386/tcg-target.c
+++ b/tcg/i386/tcg-target.c
@@ -104,6 +104,10 @@ static const int tcg_target_call_oarg_re
 # define have_cmov 1
 #elif defined(CONFIG_CPUID_H)
 #include <cpuid.h>
+#ifndef bit_CMOV
+/* clang's <cpuid.h> doesn't define bit_* */
+#define bit_CMOV	(1 << 15)
+#endif
 static bool have_cmov;
 #else
 # define have_cmov 0
