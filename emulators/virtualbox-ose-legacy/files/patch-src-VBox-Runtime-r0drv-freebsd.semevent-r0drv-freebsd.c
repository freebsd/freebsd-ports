Index: src/VBox/Runtime/r0drv/freebsd/semevent-r0drv-freebsd.c
@@ -205,15 +205,23 @@ static int rtSemEventWait(RTSEMEVENT Eve
 
                 RTSpinlockRelease(pEventInt->hSpinLock, &Tmp);
 
+#if __FreeBSD_version >=800026
                 if (fInterruptible)
                     rc = sleepq_timedwait_sig(pEventInt, 0);
                 else
                     rc = sleepq_timedwait(pEventInt, 0);
+#else
+                if (fInterruptible)
+                    rc = sleepq_timedwait_sig(pEventInt);
+                else
+                    rc = sleepq_timedwait(pEventInt);
+#endif
             }
             else
             {
                 RTSpinlockRelease(pEventInt->hSpinLock, &Tmp);
 
+#if __FreeBSD_version >=800026
                 if (fInterruptible)
                     rc = sleepq_wait_sig(pEventInt, 0);
                 else
@@ -221,6 +229,15 @@ static int rtSemEventWait(RTSEMEVENT Eve
                     rc = 0;
                     sleepq_wait(pEventInt, 0);
                 }
+#else
+                if (fInterruptible)
+                    rc = sleepq_wait_sig(pEventInt);
+                else
+                {
+                    rc = 0;
+                    sleepq_wait(pEventInt);
+                }
+#endif
             }
 
             RTSpinlockAcquire(pEventInt->hSpinLock, &Tmp);
