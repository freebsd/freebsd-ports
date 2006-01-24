Index: eval.c
diff -u -p eval.c.orig eval.c
--- eval.c.orig	Tue Dec 20 22:41:47 2005
+++ eval.c	Mon Jan 23 10:01:51 2006
@@ -108,7 +108,7 @@ rb_jump_context(env, val)
     abort();			/* ensure noreturn */
 }
 /*
- * FUNCTION_CALL_MAY_RETURN_TWICE is a magic for getcontext, gcc,
+ * PRE_GETCONTEXT and POST_GETCONTEXT is a magic for getcontext, gcc,
  * IA64 register stack and SPARC register window combination problem.
  *
  * Assume following code sequence.
@@ -129,42 +129,88 @@ rb_jump_context(env, val)
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
- */
-#if defined (__GNUC__) && (defined(sparc) || defined(__sparc__))
-#define FUNCTION_CALL_MAY_RETURN_TWICE \
- ({ __asm__ volatile ("" : : :  \
-    "%o0", "%o1", "%o2", "%o3", "%o4", "%o5", "%o7", \
-    "%l0", "%l1", "%l2", "%l3", "%l4", "%l5", "%l6", "%l7", \
-    "%i0", "%i1", "%i2", "%i3", "%i4", "%i5", "%i7"); })
-#else
+ *
+ * Since the problem is fixed at gcc 4.0.3, the magic is applied only for
+ * prior versions of gcc.
+ * http://gcc.gnu.org/bugzilla/show_bug.cgi?id=21957
+ * http://gcc.gnu.org/bugzilla/show_bug.cgi?id=22127
+ */
+#  define GCC_VERSION_BEFORE(major, minor, patchlevel) \
+    (defined(__GNUC__) && !defined(__INTEL_COMPILER) && \
+     ((__GNUC__ < (major)) ||  \
+      (__GNUC__ == (major) && __GNUC_MINOR__ < (minor)) || \
+      (__GNUC__ == (major) && __GNUC_MINOR__ == (minor) && __GNUC_PATCHLEVEL__ < (patchlevel))))
+#  if GCC_VERSION_BEFORE(4,0,3) && (defined(sparc) || defined(__sparc__))
+#    ifdef __pic__
+/*
+ * %l7 is excluded for PIC because it is PIC register.
+ * http://lists.freebsd.org/pipermail/freebsd-sparc64/2006-January/003739.html
+ */
+#      define PRE_GETCONTEXT \
+	 ({ __asm__ volatile ("" : : :  \
+	    "%o0", "%o1", "%o2", "%o3", "%o4", "%o5", "%o7", \
+	    "%l0", "%l1", "%l2", "%l3", "%l4", "%l5", "%l6", \
+	    "%i0", "%i1", "%i2", "%i3", "%i4", "%i5", "%i7"); })
+#    else
+#      define PRE_GETCONTEXT \
+	 ({ __asm__ volatile ("" : : :  \
+	    "%o0", "%o1", "%o2", "%o3", "%o4", "%o5", "%o7", \
+	    "%l0", "%l1", "%l2", "%l3", "%l4", "%l5", "%l6", "%l7", \
+	    "%i0", "%i1", "%i2", "%i3", "%i4", "%i5", "%i7"); })
+#    endif
+#    define POST_GETCONTEXT PRE_GETCONTEXT
+#  elif GCC_VERSION_BEFORE(4,0,3) && defined(__ia64)
 static jmp_buf function_call_may_return_twice_jmp_buf;
-int function_call_may_return_twice_false = 0;
-#define FUNCTION_CALL_MAY_RETURN_TWICE \
-  (function_call_may_return_twice_false ? \
-   setjmp(function_call_may_return_twice_jmp_buf) : \
-   0)
-#endif
-#define ruby_longjmp(env, val) rb_jump_context(env, val)
-#define ruby_setjmp(j) ((j)->status = 0, \
-    FUNCTION_CALL_MAY_RETURN_TWICE, \
-    getcontext(&(j)->context), \
-    (j)->status)
+int function_call_may_return_twice_false_1 = 0;
+int function_call_may_return_twice_false_2 = 0;
+#    define PRE_GETCONTEXT \
+       (function_call_may_return_twice_false_1 ? \
+        setjmp(function_call_may_return_twice_jmp_buf) : \
+        0)
+#    define POST_GETCONTEXT \
+       (function_call_may_return_twice_false_2 ? \
+        setjmp(function_call_may_return_twice_jmp_buf) : \
+        0)
+#  elif defined(__FreeBSD__)
+/*
+ * workaround for FreeBSD/i386 getcontext/setcontext bug.
+ * clear the carry flag by (0 ? ... : ...).
+ * FreeBSD PR 92110 http://www.freebsd.org/cgi/query-pr.cgi?pr=92110
+ * [ruby-dev:28263]
+ */
+static int volatile freebsd_clear_carry_flag = 0;
+#    define PRE_GETCONTEXT \
+       (freebsd_clear_carry_flag ? (freebsd_clear_carry_flag = 0) : 0)
+#  endif
+#  ifndef PRE_GETCONTEXT
+#    define PRE_GETCONTEXT 0
+#  endif
+#  ifndef POST_GETCONTEXT
+#    define POST_GETCONTEXT 0
+#  endif
+#  define ruby_longjmp(env, val) rb_jump_context(env, val)
+#  define ruby_setjmp(j) ((j)->status = 0, \
+     PRE_GETCONTEXT, \
+     getcontext(&(j)->context), \
+     POST_GETCONTEXT, \
+     (j)->status)
 #else
 typedef jmp_buf rb_jmpbuf_t;
-#if !defined(setjmp) && defined(HAVE__SETJMP)
-#define ruby_setjmp(env) _setjmp(env)
-#define ruby_longjmp(env,val) _longjmp(env,val)
-#else
-#define ruby_setjmp(env) setjmp(env)
-#define ruby_longjmp(env,val) longjmp(env,val)
-#endif
+#  if !defined(setjmp) && defined(HAVE__SETJMP)
+#    define ruby_setjmp(env) _setjmp(env)
+#    define ruby_longjmp(env,val) _longjmp(env,val)
+#  else
+#    define ruby_setjmp(env) setjmp(env)
+#    define ruby_longjmp(env,val) longjmp(env,val)
+#  endif
 #endif
 
 #include <sys/types.h>
