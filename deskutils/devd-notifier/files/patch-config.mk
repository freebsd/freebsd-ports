--- config.mk.orig	2012-05-10 00:23:31.000000000 +0200
+++ config.mk	2012-05-10 00:23:55.000000000 +0200
@@ -11,7 +11,7 @@
 INCS = `pkg-config --cflags libnotify`
 LIBS = `pkg-config --libs libnotify`
 
-CFLAGS += -std=c99 -pedantic -Wall -Os ${INCS}
-LDFLAGS = -g ${LIBS}
+CFLAGS += -std=c99 -pedantic -Wall ${INCS}
+LDFLAGS += ${LIBS}
 
 CC? = cc
