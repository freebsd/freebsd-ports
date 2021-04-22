https://github.com/spring/pr-downloader/pull/140

--- tools/pr-downloader/src/Downloader/Rapid/Sdp.cpp.orig	2020-12-20 17:04:22 UTC
+++ tools/pr-downloader/src/Downloader/Rapid/Sdp.cpp
@@ -5,6 +5,7 @@
 #include <stdio.h>
 #include <curl/curl.h>
 #include <stdlib.h>
+#include <errno.h>
 
 #include "Sdp.h"
 #include "RapidDownloader.h"
