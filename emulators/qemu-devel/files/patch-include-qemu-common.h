From brad@comstyle.com Tue May 21 22:45:57 CEST 2013
From: brad@comstyle.com (Brad Smith)
Subject: [Qemu-devel] [PATCH] ui/gtk.c: Fix *BSD build of Gtk+ UI
Date: Tue, 21 May 2013 12:14:24 -0400
Message-ID: <20130521161324.GA29977@rox.home.comstyle.com>

Fix the build of the Gtk+ UI on *BSD systems.

Signed-off-by: Brad Smith <brad@comstyle.com>

diff --git a/include/qemu-common.h b/include/qemu-common.h
index af769f5..c944bb7 100644
--- a/include/qemu-common.h
+++ b/include/qemu-common.h
@@ -45,6 +45,7 @@
 #if defined(__GLIBC__)
 # include <pty.h>
 #elif defined CONFIG_BSD
+# include <termios.h>
 # if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
 #  include <libutil.h>
 # else

-- 
This message has been scanned for viruses and
dangerous content by MailScanner, and is
believed to be clean.



