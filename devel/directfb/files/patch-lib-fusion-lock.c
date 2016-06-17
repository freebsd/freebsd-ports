--- lib/fusion/lock.c.orig	2012-05-23 13:43:12 UTC
+++ lib/fusion/lock.c
@@ -646,7 +646,7 @@ fusion_skirmish_wait( FusionSkirmish *sk
       
      /* Install a (fake) signal handler for SIGRESTART. */
      act.sa_handler = restart_handler;
-     act.sa_flags   = SA_RESETHAND | SA_RESTART | SA_NOMASK;
+     act.sa_flags   = SA_RESETHAND | SA_RESTART | SA_NODEFER;
      
      sigaction( SIGRESTART, &act, &oldact );
      
