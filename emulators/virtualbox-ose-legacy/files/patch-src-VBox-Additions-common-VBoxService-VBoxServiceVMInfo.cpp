--- src/VBox/Additions/common/VBoxService/VBoxServiceVMInfo.cpp.orig	2010-01-18 10:53:11.000000000 +0100
+++ src/VBox/Additions/common/VBoxService/VBoxServiceVMInfo.cpp	2010-01-18 10:53:18.000000000 +0100
@@ -38,7 +38,6 @@
 # include <sys/socket.h>
 # include <net/if.h>
 # include <unistd.h>
-# include <utmp.h>
 # ifdef RT_OS_SOLARIS
 #  include <sys/sockio.h>
 # endif
