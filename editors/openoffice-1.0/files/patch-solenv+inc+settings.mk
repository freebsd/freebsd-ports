--- ../solenv/inc/settings.mk.orig	Fri Mar  8 10:23:21 2002
+++ ../solenv/inc/settings.mk	Tue May 28 12:56:27 2002
@@ -166,7 +166,6 @@
 CDEFSOPT=
 HDEFS=
 
-CC=
 .IF "$(add_cflags)"!=""
 ENVCFLAGS+=$(add_cflags)
 .ENDIF
@@ -264,8 +263,6 @@
 AS=
 BC=
 COBOL=
-CPP=
-CXX=
 FOR=
 PASCAL=
 
