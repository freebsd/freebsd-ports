Author: asl
Date: Wed Sep 26 02:36:55 2007
New Revision: 42351

Log:
FreeBSD really supports #pragma pack(push). This fixes PR1702

==============================================================================
--- ../gcc/config/freebsd.h (original)
+++ ../gcc/config/freebsd.h Wed Sep 26 02:36:55 2007
@@ -85,3 +85,7 @@
    This enables the test coverage code to use file locking when exiting a
    program, which avoids race conditions if the program has forked.  */
 #define TARGET_HAS_F_SETLKW
+
+/* LLVM LOCAL begin */
+#define HANDLE_PRAGMA_PACK_PUSH_POP
+/* LLVM LOCAL end */
