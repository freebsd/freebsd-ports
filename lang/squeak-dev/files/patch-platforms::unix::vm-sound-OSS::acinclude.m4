--- platforms/unix/vm-sound-OSS/acinclude.m4.orig	Mon May 10 10:18:03 2004
+++ platforms/unix/vm-sound-OSS/acinclude.m4	Mon May 10 10:18:22 2004
@@ -1,7 +1,7 @@
 # -*- sh -*-
 
 AC_MSG_CHECKING([for Open Sound System])
-AC_TRY_COMPILE([#include <sys/soundcard.h>],[OPEN_SOUND_SYSTEM;],[
+AC_TRY_COMPILE([#include <sys/soundcard.h>],[EV_SEQ_LOCAL;],[
   AC_MSG_RESULT(yes)
 ],[
   AC_MSG_RESULT(no)
