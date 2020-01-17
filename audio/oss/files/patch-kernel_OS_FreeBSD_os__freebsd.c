--- kernel/OS/FreeBSD/os_freebsd.c.orig	2020-01-07 14:59:06 UTC
+++ kernel/OS/FreeBSD/os_freebsd.c
@@ -473,7 +473,7 @@ typedef struct tmout_desc
   void (*func) (void *);
   void *arg;
 
-  struct callout_handle timer;
+  struct callout timer;
 } tmout_desc_t;
 
 static volatile int next_id = 0;
@@ -483,12 +483,17 @@ tmout_desc_t tmouts[MAX_TMOUTS] = { {0} };
 
 int timeout_random = 0x12123400;
 
+static struct mtx oss_timeout_mutex;
+
 void
 oss_timer_callback (void *arg)
 {
   int ix;
+  void (*func) (void *);
   tmout_desc_t *tmout = arg;
 
+  /* oss_timeout_mutex locked by callout */
+
   timeout_random++;
 
   if (!tmout->active)
@@ -498,7 +503,10 @@ oss_timer_callback (void *arg)
   tmout->active = 0;
   tmout->timestamp = 0;
 
-  tmout->func (arg);
+  func = tmout->func;
+  mtx_unlock(&oss_timeout_mutex);
+
+  func (arg);
 }
 
 timeout_id_t
@@ -507,6 +515,8 @@ oss_timeout (void (*func) (void *), void *arg, unsigne
   tmout_desc_t *tmout = NULL;
   int id, n;
 
+  mtx_lock(&oss_timeout_mutex);
+
   timeout_random++;
 
   n = 0;
@@ -527,6 +537,7 @@ oss_timeout (void (*func) (void *), void *arg, unsigne
 
   if (id == -1)			/* No timer slots available */
     {
+      mtx_unlock(&oss_timeout_mutex);
       cmn_err (CE_CONT, "Timeout table full\n");
       return 0;
     }
@@ -535,8 +546,10 @@ oss_timeout (void (*func) (void *), void *arg, unsigne
   tmout->arg = arg;
   tmout->timestamp = id | (timeout_random & ~0xff);
 
-  tmout->timer = timeout (oss_timer_callback, tmout, ticks);
+  callout_reset(&tmout->timer, ticks, oss_timer_callback, tmout);
 
+  mtx_unlock(&oss_timeout_mutex);
+
   return id | (timeout_random & ~0xff);
 }
 
@@ -550,15 +563,19 @@ oss_untimeout (timeout_id_t id)
   if (ix < 0 || ix >= MAX_TMOUTS)
     return;
 
+  mtx_lock(&oss_timeout_mutex);
+
   timeout_random++;
   tmout = &tmouts[ix];
 
   if (tmout->timestamp != id)	/* Expired timer */
     return;
   if (tmout->active)
-    untimeout (oss_timer_callback, tmout, tmout->timer);
+    callout_stop(&tmout->timer);
   tmout->active = 0;
   tmout->timestamp = 0;
+
+  mtx_unlock(&oss_timeout_mutex);
 }
 
 int
@@ -618,6 +635,7 @@ oss_get_walltime (void)
 int
 soundcard_attach (void)
 {
+  int i;
   oss_device_t *osdev;
 
   if (module_lookupbyname("sound") != NULL)
@@ -649,6 +667,12 @@ soundcard_attach (void)
 
   oss_common_init (osdev);
 
+  mtx_init(&oss_timeout_mutex, "OSS timeout", NULL, MTX_DEF);
+
+  for (i = 0; i < MAX_TMOUTS; ++i)
+	callout_init_mtx(&tmouts[i].timer, &oss_timeout_mutex,
+			 CALLOUT_RETURNUNLOCKED);
+
   return 0;
 }
 
@@ -659,6 +683,11 @@ soundcard_detach (void)
 
   if (refcount > 0 || open_devices > 0)
     return EBUSY;
+
+  for (i = 0; i < MAX_TMOUTS; ++i)
+	callout_drain(&tmouts[i].timer);
+
+  mtx_destroy(&oss_timeout_mutex);
 
   oss_unload_drivers ();
 
