--- src/audiointerface.c.orig	2012-09-20 22:44:28.771017000 +0900
+++ src/audiointerface.c	2012-10-05 06:05:30.000000000 +0900
@@ -14,6 +14,7 @@
 #include "audiointerface.h"
 #include "eventqueue.h"
 #include "dummybackend.h"
+#include "sourceaudio.h"
 
 #ifdef _HAVE_JACK_
   #include "jackbackend.h"
