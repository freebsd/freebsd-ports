--- src/util/screensaver.cpp	2018-04-22 02:22:56.333283000 -0500
+++ src/util/screensaver.cpp	2018-04-22 02:24:03.836501000 -0500
@@ -23,13 +23,13 @@
 #  include "util/mac.h"
 #elif defined(Q_OS_WIN)
 #  include <windows.h>
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 #  include <QtDBus>
 #elif HAVE_XSCREENSAVER_SUSPEND
 #  include <X11/extensions/scrnsaver.h>
 #endif // Q_OS_WIN
 
-#if defined(Q_OS_LINUX) || HAVE_XSCREENSAVER_SUSPEND
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || HAVE_XSCREENSAVER_SUSPEND
 #  define None XNone
 #  define Window XWindow
 #  include <X11/Xlib.h>
@@ -140,7 +140,7 @@
     s_enabled = false;
 }
 
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 const char *SCREENSAVERS[][4] = {
     // org.freedesktop.ScreenSaver is the standard. should work for gnome and kde too, 
     // but I add their specific names too
