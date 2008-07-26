--- src/pulsecore/protocol-native.c.orig	2008-07-26 17:04:23.000000000 -0400
+++ src/pulsecore/protocol-native.c	2008-07-26 17:08:27.000000000 -0400
@@ -2058,6 +2058,7 @@ static void command_auth(PA_GCC_UNUSED p
         if (c->version < 10 || (c->version >= 13 && !shm_on_remote))
             do_shm = FALSE;
 
+#ifdef HAVE_CREDS
     if (do_shm) {
         /* Only enable SHM if both sides are owned by the same
          * user. This is a security measure because otherwise data
@@ -2067,6 +2068,7 @@ static void command_auth(PA_GCC_UNUSED p
         if (!(creds = pa_pdispatch_creds(pd)) || getuid() != creds->uid)
             do_shm = FALSE;
     }
+#endif
 
     pa_log_debug("Negotiated SHM: %s", pa_yes_no(do_shm));
     pa_pstream_enable_shm(c->pstream, do_shm);
