- bugfix, patch reported to the author via e-mail.

--- app/audio-subs.c.orig	2021-05-18 15:20:58 UTC
+++ app/audio-subs.c
@@ -138,7 +138,7 @@ union audio_backpipe_args {
 
     struct _cmderrno {
         audio_backpipe_id cmd;
-        gint errno;
+        gint errno_;
         gint length;
         gchar text[1];
     } __attribute__((packed)) cmderrno;
@@ -293,7 +293,7 @@ void audio_backpipe_write(audio_backpipe_id cmd, ...)
         arg_size = l + sizeof(args->cmderrno);
         args = arg_pointer = alloca(arg_size);
         args->cmderrno.cmd = cmd;
-        args->cmderrno.errno = va_arg(arg_list, gint);
+        args->cmderrno.errno_ = va_arg(arg_list, gint);
         args->cmderrno.length = l;
         strncpy(args->cmderrno.text, line, l + 1);
         break;
