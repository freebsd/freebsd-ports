--- src/libs/xpcom18a4/xpcom/reflect/xptcall/src/md/unix/xptcinvoke_x86_64_linux.cpp.orig	2019-10-10 18:15:53 UTC
+++ src/libs/xpcom18a4/xpcom/reflect/xptcall/src/md/unix/xptcinvoke_x86_64_linux.cpp
@@ -143,11 +143,22 @@ XPTC_InvokeByIndex(nsISupports * that, PRUint32 method
     if (nr_stack)
         nr_stack = (nr_stack + 1) & ~1;
 
+#if !defined(VBOX_WITH_GCC_SANITIZER) && !defined(__clang__)
     // Load parameters to stack, if necessary
     PRUint64 *stack = (PRUint64 *) __builtin_alloca(nr_stack * 8);
+#else
+    typedef struct { PRUint64 stack[20]; } methodStack;
+    if (nr_stack > 20)
+        return NS_ERROR_CALL_FAILED;
+    methodStack stack;
+#endif
     PRUint64 gpregs[GPR_COUNT];
     double fpregs[FPR_COUNT];
+#if !defined(VBOX_WITH_GCC_SANITIZER) && !defined(__clang__)
     invoke_copy_to_stack(stack, paramCount, params, gpregs, fpregs);
+#else
+    invoke_copy_to_stack(stack.stack, paramCount, params, gpregs, fpregs);
+#endif
 
     // Load FPR registers from fpregs[]
     register double d0 asm("xmm0");
@@ -205,7 +216,12 @@ XPTC_InvokeByIndex(nsISupports * that, PRUint32 method
     methodAddress += 8 * methodIndex;
     methodAddress = *((PRUint64 *)methodAddress);
     
+#if !defined(VBOX_WITH_GCC_SANITIZER) && !defined(__clang__)
     typedef PRUint32 (*Method)(PRUint64, PRUint64, PRUint64, PRUint64, PRUint64, PRUint64);
     PRUint32 result = ((Method)methodAddress)(a0, a1, a2, a3, a4, a5);
+#else
+    typedef PRUint32 (*Method)(PRUint64, PRUint64, PRUint64, PRUint64, PRUint64, PRUint64, methodStack);
+    PRUint32 result = ((Method)methodAddress)(a0, a1, a2, a3, a4, a5, stack);
+#endif
     return result;
 }
