--- src/modules/oss/module-oss.c.orig	2024-01-12 17:22:09 UTC
+++ src/modules/oss/module-oss.c
@@ -121,9 +121,6 @@ struct userdata {
     int fd;
     int mode;
 
-    int mixer_fd;
-    int mixer_devmask;
-
     int nfrags, frag_size, orig_frag_size;
 
     bool shutdown;
@@ -819,75 +816,145 @@ static int source_set_state_in_io_thread_cb(pa_source 
     return 0;
 }
 
+static int open_mixer(struct userdata *u, int *p_devmask) {
+    int mixer_fd;
+
+    mixer_fd = pa_oss_open_mixer_for_device(u->device_name);
+    if (mixer_fd < 0)
+        return (mixer_fd);
+
+    if (ioctl(mixer_fd, SOUND_MIXER_READ_DEVMASK, p_devmask) < 0) {
+        pa_log_warn("SOUND_MIXER_READ_DEVMASK failed: %s", pa_cstrerror(errno));
+        pa_close(mixer_fd);
+        return (-1);
+    }
+    return (mixer_fd);
+}
+
+static void oss_get_dummy_volume(const pa_sample_spec *ss, pa_cvolume *volume) {
+    char cv[PA_CVOLUME_SNPRINT_VERBOSE_MAX];
+    unsigned vol;
+
+    pa_assert(ss);
+    pa_assert(volume);
+
+    vol = 100 | (100 << 8);
+
+    pa_cvolume_reset(volume, ss->channels);
+
+    volume->values[0] = PA_CLAMP_VOLUME(((vol & 0xFF) * PA_VOLUME_NORM) / 100);
+
+    if (volume->channels >= 2)
+        volume->values[1] = PA_CLAMP_VOLUME((((vol >> 8) & 0xFF) * PA_VOLUME_NORM) / 100);
+
+    pa_log_debug("Read dummy settings: %s", pa_cvolume_snprint_verbose(cv, sizeof(cv), volume, NULL, false));
+}
+
 static void sink_get_volume(pa_sink *s) {
     struct userdata *u;
 
+    int mixer_fd;
+    int mixer_devmask;
+
     pa_assert_se(u = s->userdata);
 
-    pa_assert(u->mixer_devmask & (SOUND_MASK_VOLUME|SOUND_MASK_PCM));
+    mixer_fd = open_mixer(u, &mixer_devmask);
+    if (mixer_fd < 0) {
+        oss_get_dummy_volume(&s->sample_spec, &s->real_volume);
+        return;
+    }
 
-    if (u->mixer_devmask & SOUND_MASK_VOLUME)
-        if (pa_oss_get_volume(u->mixer_fd, SOUND_MIXER_READ_VOLUME, &s->sample_spec, &s->real_volume) >= 0)
-            return;
+    if (mixer_devmask & SOUND_MASK_VOLUME)
+        if (pa_oss_get_volume(mixer_fd, SOUND_MIXER_READ_VOLUME, &s->sample_spec, &s->real_volume) >= 0)
+            goto done;
 
-    if (u->mixer_devmask & SOUND_MASK_PCM)
-        if (pa_oss_get_volume(u->mixer_fd, SOUND_MIXER_READ_PCM, &s->sample_spec, &s->real_volume) >= 0)
-            return;
+    if (mixer_devmask & SOUND_MASK_PCM)
+        if (pa_oss_get_volume(mixer_fd, SOUND_MIXER_READ_PCM, &s->sample_spec, &s->real_volume) >= 0)
+            goto done;
 
+    oss_get_dummy_volume(&s->sample_spec, &s->real_volume);
+
     pa_log_info("Device doesn't support reading mixer settings: %s", pa_cstrerror(errno));
+done:
+    pa_close(mixer_fd);
 }
 
 static void sink_set_volume(pa_sink *s) {
     struct userdata *u;
 
+    int mixer_fd;
+    int mixer_devmask;
+
     pa_assert_se(u = s->userdata);
 
-    pa_assert(u->mixer_devmask & (SOUND_MASK_VOLUME|SOUND_MASK_PCM));
+    mixer_fd = open_mixer(u, &mixer_devmask);
+    if (mixer_fd < 0)
+        return;
 
-    if (u->mixer_devmask & SOUND_MASK_VOLUME)
-        (void) pa_oss_set_volume(u->mixer_fd, SOUND_MIXER_WRITE_VOLUME, &s->sample_spec, &s->real_volume);
+    if (mixer_devmask & SOUND_MASK_VOLUME)
+        (void) pa_oss_set_volume(mixer_fd, SOUND_MIXER_WRITE_VOLUME, &s->sample_spec, &s->real_volume);
 
-    if (u->mixer_devmask & SOUND_MASK_PCM)
-        (void) pa_oss_set_volume(u->mixer_fd, SOUND_MIXER_WRITE_PCM, &s->sample_spec, &s->real_volume);
+    if (mixer_devmask & SOUND_MASK_PCM)
+        (void) pa_oss_set_volume(mixer_fd, SOUND_MIXER_WRITE_PCM, &s->sample_spec, &s->real_volume);
+
+    pa_close(mixer_fd);
 }
 
 static void source_get_volume(pa_source *s) {
     struct userdata *u;
 
+    int mixer_fd;
+    int mixer_devmask;
+
     pa_assert_se(u = s->userdata);
 
-    pa_assert(u->mixer_devmask & (SOUND_MASK_MIC|SOUND_MASK_IGAIN|SOUND_MASK_RECLEV));
+    mixer_fd = open_mixer(u, &mixer_devmask);
+    if (mixer_fd < 0) {
+        oss_get_dummy_volume(&s->sample_spec, &s->real_volume);
+        return;
+    }
 
-    if (u->mixer_devmask & SOUND_MASK_IGAIN)
-        if (pa_oss_get_volume(u->mixer_fd, SOUND_MIXER_READ_IGAIN, &s->sample_spec, &s->real_volume) >= 0)
-            return;
+    if (mixer_devmask & SOUND_MASK_IGAIN)
+        if (pa_oss_get_volume(mixer_fd, SOUND_MIXER_READ_IGAIN, &s->sample_spec, &s->real_volume) >= 0)
+                goto done;
 
-    if (u->mixer_devmask & SOUND_MASK_RECLEV)
-        if (pa_oss_get_volume(u->mixer_fd, SOUND_MIXER_READ_RECLEV, &s->sample_spec, &s->real_volume) >= 0)
-            return;
+    if (mixer_devmask & SOUND_MASK_RECLEV)
+        if (pa_oss_get_volume(mixer_fd, SOUND_MIXER_READ_RECLEV, &s->sample_spec, &s->real_volume) >= 0)
+                goto done;
 
-    if (u->mixer_devmask & SOUND_MASK_MIC)
-        if (pa_oss_get_volume(u->mixer_fd, SOUND_MIXER_READ_MIC, &s->sample_spec, &s->real_volume) >= 0)
-            return;
+    if (mixer_devmask & SOUND_MASK_MIC)
+        if (pa_oss_get_volume(mixer_fd, SOUND_MIXER_READ_MIC, &s->sample_spec, &s->real_volume) >= 0)
+                goto done;
 
+    oss_get_dummy_volume(&s->sample_spec, &s->real_volume);
+
     pa_log_info("Device doesn't support reading mixer settings: %s", pa_cstrerror(errno));
+done:
+    pa_close(mixer_fd);
 }
 
 static void source_set_volume(pa_source *s) {
     struct userdata *u;
 
+    int mixer_fd;
+    int mixer_devmask;
+
     pa_assert_se(u = s->userdata);
 
-    pa_assert(u->mixer_devmask & (SOUND_MASK_MIC|SOUND_MASK_IGAIN|SOUND_MASK_RECLEV));
+    mixer_fd = open_mixer(u, &mixer_devmask);
+    if (mixer_fd < 0)
+        return;
 
-    if (u->mixer_devmask & SOUND_MASK_IGAIN)
-        (void) pa_oss_set_volume(u->mixer_fd, SOUND_MIXER_WRITE_IGAIN, &s->sample_spec, &s->real_volume);
+    if (mixer_devmask & SOUND_MASK_IGAIN)
+        (void) pa_oss_set_volume(mixer_fd, SOUND_MIXER_WRITE_IGAIN, &s->sample_spec, &s->real_volume);
 
-    if (u->mixer_devmask & SOUND_MASK_RECLEV)
-        (void) pa_oss_set_volume(u->mixer_fd, SOUND_MIXER_WRITE_RECLEV, &s->sample_spec, &s->real_volume);
+    if (mixer_devmask & SOUND_MASK_RECLEV)
+        (void) pa_oss_set_volume(mixer_fd, SOUND_MIXER_WRITE_RECLEV, &s->sample_spec, &s->real_volume);
 
-    if (u->mixer_devmask & SOUND_MASK_MIC)
-        (void) pa_oss_set_volume(u->mixer_fd, SOUND_MIXER_WRITE_MIC, &s->sample_spec, &s->real_volume);
+    if (mixer_devmask & SOUND_MASK_MIC)
+        (void) pa_oss_set_volume(mixer_fd, SOUND_MIXER_WRITE_MIC, &s->sample_spec, &s->real_volume);
+
+    pa_close(mixer_fd);
 }
 
 static void thread_func(void *userdata) {
@@ -1158,16 +1225,6 @@ static void thread_func(void *userdata) {
             revents = pollfd->revents;
         } else
             revents = 0;
-
-        /* check for mixer shutdown, if any */
-        if ((revents & (POLLOUT | POLLIN)) == 0) {
-            int mixer_fd = u->mixer_fd;
-            int devmask;
-            if (mixer_fd > -1 && ioctl(mixer_fd, SOUND_MIXER_READ_DEVMASK, &devmask) < 0) {
-                pa_log("Mixer shutdown.");
-                goto fail;
-            }
-        }
     }
 
 fail:
@@ -1245,6 +1302,8 @@ int pa__init(pa_module*m) {
     }
 
 #ifndef __FreeBSD__
+/* Disable mmap. The OSS on FreeBSD doesn't support read & write on
+   the same socket */
     if (use_mmap && mode == O_WRONLY) {
         pa_log_info("Device opened for playback only, cannot do memory mapping, falling back to UNIX write() mode.");
         use_mmap = false;
@@ -1277,8 +1336,6 @@ int pa__init(pa_module*m) {
     u->module = m;
     m->userdata = u;
     u->fd = fd;
-    u->mixer_fd = -1;
-    u->mixer_devmask = 0;
     u->use_getospace = u->use_getispace = true;
     u->use_getodelay = true;
     u->mode = mode;
@@ -1449,36 +1506,19 @@ int pa__init(pa_module*m) {
             u->out_mmap_memblocks = pa_xnew0(pa_memblock*, u->out_nfrags);
     }
 
-    if ((u->mixer_fd = pa_oss_open_mixer_for_device(u->device_name)) >= 0) {
-        bool do_close = true;
-
-        if (ioctl(u->mixer_fd, SOUND_MIXER_READ_DEVMASK, &u->mixer_devmask) < 0)
-            pa_log_warn("SOUND_MIXER_READ_DEVMASK failed: %s", pa_cstrerror(errno));
-        else {
-            if (u->sink && (u->mixer_devmask & (SOUND_MASK_VOLUME|SOUND_MASK_PCM))) {
-                pa_log_debug("Found hardware mixer track for playback.");
-                pa_sink_set_get_volume_callback(u->sink, sink_get_volume);
-                pa_sink_set_set_volume_callback(u->sink, sink_set_volume);
-                u->sink->n_volume_steps = 101;
-                do_close = false;
-            }
-
-            if (u->source && (u->mixer_devmask & (SOUND_MASK_MIC|SOUND_MASK_RECLEV|SOUND_MASK_IGAIN))) {
-                pa_log_debug("Found hardware mixer track for recording.");
-                pa_source_set_get_volume_callback(u->source, source_get_volume);
-                pa_source_set_set_volume_callback(u->source, source_set_volume);
-                u->source->n_volume_steps = 101;
-                do_close = false;
-            }
-        }
-
-        if (do_close) {
-            pa_close(u->mixer_fd);
-            u->mixer_fd = -1;
-            u->mixer_devmask = 0;
-        }
+    if (u->sink) {
+        pa_log_debug("Found hardware mixer track for playback.");
+        pa_sink_set_get_volume_callback(u->sink, sink_get_volume);
+        pa_sink_set_set_volume_callback(u->sink, sink_set_volume);
+        u->sink->n_volume_steps = 101;
     }
 
+    if (u->source) {
+        pa_log_debug("Found hardware mixer track for recording.");
+        pa_source_set_get_volume_callback(u->source, source_get_volume);
+        pa_source_set_set_volume_callback(u->source, source_set_volume);
+        u->source->n_volume_steps = 101;
+    }
 go_on:
 
     pa_assert(u->source || u->sink);
@@ -1594,9 +1634,6 @@ void pa__done(pa_module*m) {
 
     if (u->fd >= 0)
         pa_close(u->fd);
-
-    if (u->mixer_fd >= 0)
-        pa_close(u->mixer_fd);
 
     pa_xfree(u->device_name);
 
