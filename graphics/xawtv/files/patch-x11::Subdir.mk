--- x11/Subdir.mk.orig	Sat Jun 22 17:13:04 2002
+++ x11/Subdir.mk	Sat Jun 22 17:13:43 2002
@@ -83,12 +83,12 @@
 # libraries to link
 x11/xawtv        : LDLIBS  := \
 	$(THREAD_LIBS) $(CURSES_LIBS) $(LIRC_LIBS) $(ALSA_LIBS) \
-	$(ATHENA_LIBS) $(VBI_LIBS) -ljpeg -lm
+	$(ATHENA_LIBS) $(VBI_LIBS) -L%%LOCALBASE%%/lib -ljpeg -lm
 x11/motv         : LDLIBS  := \
 	$(THREAD_LIBS) $(CURSES_LIBS) $(LIRC_LIBS) $(ALSA_LIBS) \
-	$(MOTIF_LIBS) $(VBI_LIBS) -ljpeg -lm
+	$(MOTIF_LIBS) $(VBI_LIBS) -L%%LOCALBASE%%/lib -ljpeg -lm
 x11/mtt          : LDLIBS  := $(THREAD_LIBS) $(MOTIF_LIBS) $(VBI_LIBS)
-x11/v4lctl       : LDLIBS  := $(THREAD_LIBS) $(ATHENA_LIBS) -ljpeg -lm
+x11/v4lctl       : LDLIBS  := $(THREAD_LIBS) $(ATHENA_LIBS) -L%%LOCALBASE%%/lib -ljpeg -lm
 x11/rootv        : LDLIBS  := $(ATHENA_LIBS)
 x11/xawtv-remote : LDLIBS  := $(ATHENA_LIBS)
 x11/propwatch    : LDLIBS  := $(ATHENA_LIBS)
