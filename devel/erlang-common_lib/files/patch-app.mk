--- app.mk.orig	2012-01-11 12:00:24 UTC
+++ app.mk
@@ -25,7 +25,7 @@ STUB_EFLAGS = -W0 -o stubs
 CD = cd
 CP = cp -vf
 ECHO = echo
-ERLDOC = ndoc
+ERLDOC = txt2tags
 LN = ln -sf
 MKDIR = mkdir
 MV = mv -vf
