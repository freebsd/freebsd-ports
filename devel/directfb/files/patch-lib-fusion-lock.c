--- lib/fusion/lock.c
+++ lib/fusion/lock.c
@@ -485,7 +485,7 @@ fusion_skirmish_wait( FusionSkirmish *skirmish, unsigned int timeout )
       
      /* Install a (fake) signal handler for SIGRESTART. */
      act.sa_handler = restart_handler;
-     act.sa_flags   = SA_RESETHAND | SA_RESTART | SA_NOMASK;
+     act.sa_flags   = SA_RESETHAND | SA_RESTART | SA_NODEFER;
      
      sigaction( SIGRESTART, &act, &oldact );
      
