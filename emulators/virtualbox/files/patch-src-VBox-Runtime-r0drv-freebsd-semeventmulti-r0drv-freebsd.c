Index: src/VBox/Runtime/r0drv/freebsd/semeventmulti-r0drv-freebsd.c
@@ -215,15 +215,23 @@ static int rtSemEventMultiWait(RTSEMEVEN
 
                 RTSpinlockRelease(pEventMultiInt->hSpinLock, &Tmp);
 
+#if __FreeBSD_version >=800026
                 if (fInterruptible)
                     rc = sleepq_timedwait_sig(pEventMultiInt, 0);
                 else
                     rc = sleepq_timedwait(pEventMultiInt, 0);
+#else
+                if (fInterruptible)
+                    rc = sleepq_timedwait_sig(pEventMultiInt);
+                else
+                    rc = sleepq_timedwait(pEventMultiInt);
+#endif
             }
             else
             {
                 RTSpinlockRelease(pEventMultiInt->hSpinLock, &Tmp);
 
+#if __FreeBSD_version >=800026
                 if (fInterruptible)
                     rc = sleepq_wait_sig(pEventMultiInt, 0);
                 else
@@ -231,6 +239,15 @@ static int rtSemEventMultiWait(RTSEMEVEN
                     rc = 0;
                     sleepq_wait(pEventMultiInt, 0);
                 }
+#else
+                if (fInterruptible)
+                    rc = sleepq_wait_sig(pEventMultiInt);
+                else
+                {
+                    rc = 0;
+                    sleepq_wait(pEventMultiInt);
+                }
+#endif
             }
 
             RTSpinlockAcquire(pEventMultiInt->hSpinLock, &Tmp);
