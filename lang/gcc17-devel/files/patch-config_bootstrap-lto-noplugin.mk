--- config/bootstrap-lto-noplugin.mk.orig	2026-10-04 22:32:07 UTC
+++ config/bootstrap-lto-noplugin.mk
@@ -6,4 +6,4 @@ STAGEfeedback_CFLAGS += -flto=jobserver -frandom-seed=
 STAGEprofile_CFLAGS += -flto=jobserver -frandom-seed=1
 STAGEtrain_CFLAGS += -flto=jobserver -frandom-seed=1
 STAGEfeedback_CFLAGS += -flto=jobserver -frandom-seed=1
-do-compare = /bin/true
+do-compare = true
