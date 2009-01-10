--- src/oss.c.orig	2008-09-01 19:53:47.000000000 -0400
+++ src/oss.c	2008-12-21 13:51:09.000000000 -0500
@@ -235,7 +235,7 @@ static int open_oss(ca_context *c, struc
     ca_return_val_if_fail(c, CA_ERROR_INVALID);
     ca_return_val_if_fail(c->private, CA_ERROR_STATE);
     ca_return_val_if_fail(out, CA_ERROR_INVALID);
-    ca_return_val_if_fail(ca_sound_file_get_nchannels(out->file) > 2, CA_ERROR_NOTSUPPORTED);
+    ca_return_val_if_fail(ca_sound_file_get_nchannels(out->file) <= 2, CA_ERROR_NOTSUPPORTED);
 
     p = PRIVATE(c);
 
@@ -258,7 +258,7 @@ static int open_oss(ca_context *c, struc
             val = AFMT_S16_NE;
             break;
         case CA_SAMPLE_S16RE:
-#if __BYTE_ORDER == __LITTLE_ENDIAN
+#if _BYTE_ORDER == _LITTLE_ENDIAN
             val = AFMT_S16_BE;
 #else
             val = AFMT_S16_LE;
@@ -423,6 +423,7 @@ int driver_play(ca_context *c, uint32_t 
     out->callback = cb;
     out->userdata = userdata;
     out->pipe_fd[0] = out->pipe_fd[1] = -1;
+    out->pcm = -1;
 
     if (pipe(out->pipe_fd) < 0) {
         ret = CA_ERROR_SYSTEM;
