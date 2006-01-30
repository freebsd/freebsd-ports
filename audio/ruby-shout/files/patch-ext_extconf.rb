--- ext/extconf.rb.orig	Sun Nov 20 15:53:45 2005
+++ ext/extconf.rb	Mon Jan 30 17:23:19 2006
@@ -3,7 +3,7 @@
 dir_config("shout")
 have_library("ogg", "oggpack_writeinit")
 have_library("vorbis", "vorbis_dsp_clear")
-have_library("pthread", "pthread_create")
+have_library("speex", "speex_decode")
 if find_library("shout", "shout_init","/usr","/usr/local") and have_header("shout/shout.h")
     create_makefile("shout")
 else
