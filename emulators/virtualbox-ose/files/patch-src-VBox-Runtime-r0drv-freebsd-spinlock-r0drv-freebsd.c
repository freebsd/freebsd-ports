Index: src/VBox/Runtime/r0drv/freebsd/spinlock-r0drv-freebsd.c
@@ -171,7 +171,12 @@ RTDECL(void) RTSpinlockAcquire(RTSPINLOC
     AssertPtr(pThis);
     Assert(pThis->u32Magic == RTSPINLOCK_MAGIC);
 #ifdef RT_STRICT
+#if 0
+    /* This can't work because at least RTPowerNotificationRegister calls
+     * RTSpinlockAcquire with *pTmp allocated on the stack.
+     */
     Assert(pTmp->uFlags == 0);
+#endif
     pTmp->uFlags = 42;
 #endif
 
