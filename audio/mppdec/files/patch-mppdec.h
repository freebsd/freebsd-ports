--- mppdec.h.orig	Mon Mar 31 15:42:01 2003
+++ mppdec.h	Mon Mar 31 15:42:13 2003
@@ -129,7 +129,7 @@
 # elif defined __bsdi__
 #  include <sys/soundcard.h>
 # elif defined __FreeBSD__
-#  include <machine/soundcard.h>
+#  include <sys/soundcard.h>
 # elif defined __NetBSD__  ||  defined __OpenBSD__
 #  include <soundcard.h>
 # else
