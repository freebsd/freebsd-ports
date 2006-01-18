--- eval.c	2005/12/31 13:57:36	1.616.2.147
+++ eval.c	2006/01/18 15:01:22	1.616.2.148
@@ -129,7 +129,8 @@ rb_jump_context(env, val)
  * But it has not the problem because gcc knows setjmp may return twice.
  * gcc detects setjmp and generates setjmp safe code.
  *
- * So setjmp call before getcontext call makes the code somewhat safe.
+ * So setjmp calls before and after the getcontext call makes the code
+ * somewhat safe.
  * It fix the problem on IA64.
  * It is not required that setjmp is called at run time, since the problem is
  * register usage.
@@ -138,11 +139,23 @@ rb_jump_context(env, val)
  * inline asm is used to prohibit registers in register windows.
  */
 #if defined (__GNUC__) && (defined(sparc) || defined(__sparc__))
+#ifdef __pic__
+/*
+ * %l7 is excluded for PIC because it is PIC register.
+ * http://lists.freebsd.org/pipermail/freebsd-sparc64/2006-January/003739.html
+ */
+#define FUNCTION_CALL_MAY_RETURN_TWICE \
+ ({ __asm__ volatile ("" : : :  \
+    "%o0", "%o1", "%o2", "%o3", "%o4", "%o5", "%o7", \
+    "%l0", "%l1", "%l2", "%l3", "%l4", "%l5", "%l6", \
+    "%i0", "%i1", "%i2", "%i3", "%i4", "%i5", "%i7"); })
+#else
 #define FUNCTION_CALL_MAY_RETURN_TWICE \
  ({ __asm__ volatile ("" : : :  \
     "%o0", "%o1", "%o2", "%o3", "%o4", "%o5", "%o7", \
     "%l0", "%l1", "%l2", "%l3", "%l4", "%l5", "%l6", "%l7", \
     "%i0", "%i1", "%i2", "%i3", "%i4", "%i5", "%i7"); })
+#endif
 #else
 static jmp_buf function_call_may_return_twice_jmp_buf;
 int function_call_may_return_twice_false = 0;
@@ -155,6 +168,7 @@ int function_call_may_return_twice_false
 #define ruby_setjmp(j) ((j)->status = 0, \
     FUNCTION_CALL_MAY_RETURN_TWICE, \
     getcontext(&(j)->context), \
+    FUNCTION_CALL_MAY_RETURN_TWICE, \
     (j)->status)
 #else
 typedef jmp_buf rb_jmpbuf_t;
