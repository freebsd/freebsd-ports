--- midimountain/mcIO.cpp.orig	Thu Apr 19 11:29:46 2001
+++ midimountain/mcIO.cpp	Thu Apr 19 11:29:55 2001
@@ -1,7 +1,7 @@
 //=============================================================================
 // implementation class midi IO
 //=============================================================================
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
@@ -626,4 +626,4 @@
    }
 
    ::write(getFd(), synth_write_message, sizeof(synth_write_message));
-}
+}
