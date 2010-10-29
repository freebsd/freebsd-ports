--- _jsonlib.c.orig      2010-10-20 11:09:48.792940743 +0000
+++ _jsonlib.c   2010-10-20 11:11:06.166556561 +0000
@@ -21,6 +21,12 @@
 #include <ctype.h>
 #include <math.h>
+#if PY_VERSION_HEX < 0x02050000 && !defined(PY_SSIZE_T_MIN)
+typedef int Py_ssize_t;
+#define PY_SSIZE_T_MAX INT_MAX
+#define PY_SSIZE_T_MIN INT_MIN
+#endif
+
 /* Parser {{{ */
 typedef struct _Parser
 {
