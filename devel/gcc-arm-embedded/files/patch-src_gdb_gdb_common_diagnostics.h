--- src/gdb/gdb/common/diagnostics.h.orig	2017-06-28 22:30:08.000000000 +0300
+++ src/gdb/gdb/common/diagnostics.h	2018-01-24 17:11:46.847340000 +0300
@@ -33,7 +33,11 @@
 
 #if defined (__clang__) /* clang */
 
-# define DIAGNOSTIC_IGNORE_SELF_MOVE DIAGNOSTIC_IGNORE ("-Wself-move")
+# if __has_warning("-Wself-move")
+#  define DIAGNOSTIC_IGNORE_SELF_MOVE DIAGNOSTIC_IGNORE ("-Wself-move")
+# else
+#  define DIAGNOSTIC_IGNORE_SELF_MOVE
+# endif
 # define DIAGNOSTIC_IGNORE_DEPRECATED_REGISTER \
   DIAGNOSTIC_IGNORE ("-Wdeprecated-register")
 # define DIAGNOSTIC_IGNORE_UNUSED_FUNCTION \
