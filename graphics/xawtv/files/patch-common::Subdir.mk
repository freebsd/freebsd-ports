--- common/Subdir.mk.orig	Sat Jul 27 10:24:27 2002
+++ common/Subdir.mk	Sat Jul 27 10:22:47 2002
@@ -16,7 +16,7 @@
 	common/midictrl.o
 
 # RegEdit.c is good old K&R ...
-common/RegEdit.o : CFLAGS += -Wno-missing-prototypes -Wno-strict-prototypes
+#common/RegEdit.o : CFLAGS += -Wno-missing-prototypes -Wno-strict-prototypes
 
 common/channel-no-x11.o:: common/channel.c
 	$(CC) $(CFLAGS) -DNO_X11=1 -Wp,-MD,$*.dep -c -o $@ $<
