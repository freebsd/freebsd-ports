--- ./src/podcasts/podcastdownloader.h.orig	2013-11-24 16:04:26.803673091 -0800
+++ ./src/podcasts/podcastdownloader.h	2013-11-24 16:04:40.226672104 -0800
@@ -27,6 +27,8 @@
 #include <QRegExp>
 #include <QSet>
 
+#include <sys/time.h>
+
 class Application;
 class PodcastBackend;
 
