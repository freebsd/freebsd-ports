Index: eval.c
diff -u -p eval.c.orig eval.c
--- eval.c.orig	Tue Dec 20 22:41:47 2005
+++ eval.c	Sat Jan 21 04:13:25 2006
@@ -129,32 +129,62 @@ rb_jump_context(env, val)
  * But it has not the problem because gcc knows setjmp may return twice.
  * gcc detects setjmp and generates setjmp safe code.
  *
- * So setjmp call before getcontext call makes the code somewhat safe.
+ * So setjmp calls before and after the getcontext call makes the code
+ * somewhat safe.
  * It fix the problem on IA64.
  * It is not required that setjmp is called at run time, since the problem is
  * register usage.
  *
  * Since the magic setjmp is not enough for SPARC,
  * inline asm is used to prohibit registers in register windows.
+ *
+ * Since the problem is fixed at gcc 4.0.3, the magic is applied only for
+ * prior versions of gcc.
+ * http://gcc.gnu.org/bugzilla/show_bug.cgi?id=21957
+ * http://gcc.gnu.org/bugzilla/show_bug.cgi?id=22127
+ */
+#define GCC_VERSION_BEFORE(major, minor, patchlevel) \
+    (defined(__GNUC__) && !defined(__INTEL_COMPILER) && \
+     ((__GNUC__ < (major)) ||  \
+      (__GNUC__ == (major) && __GNUC_MINOR__ < (minor)) || \
+      (__GNUC__ == (major) && __GNUC_MINOR__ == (minor) && __GNUC_PATCHLEVEL__ < (patchlevel))))
+#if GCC_VERSION_BEFORE(4,0,3)
+#if defined(sparc) || defined(__sparc__)
+#ifdef __pic__
+/*
+ * %l7 is excluded for PIC because it is PIC register.
+ * http://lists.freebsd.org/pipermail/freebsd-sparc64/2006-January/003739.html
  */
-#if defined (__GNUC__) && (defined(sparc) || defined(__sparc__))
 #define FUNCTION_CALL_MAY_RETURN_TWICE \
  ({ __asm__ volatile ("" : : :  \
     "%o0", "%o1", "%o2", "%o3", "%o4", "%o5", "%o7", \
-    "%l0", "%l1", "%l2", "%l3", "%l4", "%l5", "%l6", "%l7", \
+    "%l0", "%l1", "%l2", "%l3", "%l4", "%l5", "%l6", \
     "%i0", "%i1", "%i2", "%i3", "%i4", "%i5", "%i7"); })
 #else
+#define FUNCTION_CALL_MAY_RETURN_TWICE \
+ ({ __asm__ volatile ("" : : :  \
+    "%o0", "%o1", "%o2", "%o3", "%o4", "%o5", "%o7", \
+    "%l0", "%l1", "%l2", "%l3", "%l4", "%l5", "%l6", "%l7", \
+    "%i0", "%i1", "%i2", "%i3", "%i4", "%i5", "%i7"); })
+#endif
+#elif defined(__ia64)
 static jmp_buf function_call_may_return_twice_jmp_buf;
 int function_call_may_return_twice_false = 0;
 #define FUNCTION_CALL_MAY_RETURN_TWICE \
   (function_call_may_return_twice_false ? \
    setjmp(function_call_may_return_twice_jmp_buf) : \
    0)
+#else
+#define FUNCTION_CALL_MAY_RETURN_TWICE 0
+#endif
+#else
+#define FUNCTION_CALL_MAY_RETURN_TWICE 0
 #endif
 #define ruby_longjmp(env, val) rb_jump_context(env, val)
 #define ruby_setjmp(j) ((j)->status = 0, \
     FUNCTION_CALL_MAY_RETURN_TWICE, \
     getcontext(&(j)->context), \
+    FUNCTION_CALL_MAY_RETURN_TWICE, \
     (j)->status)
 #else
 typedef jmp_buf rb_jmpbuf_t;
