--- src/t31.c.orig	Thu Jun 30 23:07:14 2005
+++ src/t31.c	Thu Jun 30 23:10:28 2005
@@ -51,19 +51,12 @@
 t31_profile_t profiles[3] =
 {
     {
-        .echo = TRUE,
-        .verbose = TRUE,
-        .result_code_format = ASCII_RESULT_CODES,
-        .pulse_dial = FALSE,
-        .double_escape = FALSE,
-        .s_regs[0] = 0,
-        .s_regs[3] = '\r',
-        .s_regs[4] = '\n',
-        .s_regs[5] = '\b',
-        .s_regs[6] = 1,
-        .s_regs[7] = 60,
-        .s_regs[8] = 5,
-        .s_regs[10] = 0
+        TRUE,
+        TRUE,
+        ASCII_RESULT_CODES,
+        FALSE,
+        FALSE,
+        { 0, 0, 0, '\r', '\n', '\b', 1, 60, 5, 0 }
     }
 };
 
