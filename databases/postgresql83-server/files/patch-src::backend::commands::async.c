*** src/backend/commands/async.c.orig	Sun Sep 15 21:24:41 2002
--- src/backend/commands/async.c	Mon Feb 17 21:38:47 2003
***************
*** 599,604 ****
--- 599,614 ----

  	if (notifyInterruptEnabled)
  	{
+ 		bool		save_ImmediateInterruptOK = ImmediateInterruptOK;
+
+ 		/*
+ 		 * We may be called while ImmediateInterruptOK is true; turn it off
+ 		 * while messing with the NOTIFY state.  (We would have to save
+ 		 * and restore it anyway, because PGSemaphore operations inside
+ 		 * ProcessIncomingNotify() might reset it.)
+ 		 */
+ 		ImmediateInterruptOK = false;
+
  		/*
  		 * I'm not sure whether some flavors of Unix might allow another
  		 * SIGUSR2 occurrence to recursively interrupt this routine. To
***************
*** 626,631 ****
--- 636,648 ----
  					elog(LOG, "Async_NotifyHandler: done");
  			}
  		}
+
+ 		/*
+ 		 * Restore ImmediateInterruptOK, and check for interrupts if needed.
+ 		 */
+ 		ImmediateInterruptOK = save_ImmediateInterruptOK;
+ 		if (save_ImmediateInterruptOK)
+ 			CHECK_FOR_INTERRUPTS();
  	}
  	else
  	{

