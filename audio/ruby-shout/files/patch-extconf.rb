--- extconf.rb.orig	Mon Jan 16 22:19:37 2006
+++ extconf.rb	Mon Jan 16 22:19:50 2006
@@ -3,6 +3,7 @@
 dir_config("shout")
 have_library("ogg", "oggpack_writeinit")
 have_library("vorbis", "vorbis_dsp_clear")
+have_library("speex", "speex_decode")
 have_library("pthread", "pthread_create")
 if find_library("shout", "shout_init","/usr","/usr/local") and have_header("shout/shout.h")
     create_makefile("shout")
