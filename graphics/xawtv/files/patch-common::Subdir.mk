--- common/Subdir.mk.orig	Wed Oct 30 21:06:25 2002
+++ common/Subdir.mk	Wed Oct 30 21:06:41 2002
@@ -16,10 +16,10 @@
 	common/midictrl.o
 
 # RegEdit.c is good old K&R ...
-common/RegEdit.o : CFLAGS += -Wno-missing-prototypes -Wno-strict-prototypes
-common/channel-no-x11.o: CFLAGS += -DNO_X11=1 
+#common/RegEdit.o : CFLAGS += -Wno-missing-prototypes -Wno-strict-prototypes
+#common/channel-no-x11.o: CFLAGS += -DNO_X11=1 
 
 common/channel-no-x11.o:: common/channel.c
 	@$(echo_compile_c)
-	@$(compile_c)
+	@$(compile_c) -DNO_X11=1
 	@$(fixup_deps)
