FreeBSD doesn't require/need/have -ldl
http://qa.openoffice.org/issues/show_bug.cgi?id=27043

--- ../vcl/util/makefile.mk~	Mon Mar 29 09:50:51 2004
+++ ../vcl/util/makefile.mk	Mon Mar 29 10:19:04 2004
@@ -208,7 +208,9 @@
 .IF "$(GUI)"!="UNX"
 SHL1OBJS=   $(SLO)$/salshl.obj
 .ELSE
-SHL1STDLIBS+=-ldl
+  .IF "$(OS)"!="FREEBSD"
+   SHL1STDLIBS+=-ldl
+  .ENDIF
 .ENDIF
 
 .IF "$(GUI)" != "MAC"
@@ -351,8 +353,11 @@
 # libs for gtk plugin
 SHL4STDLIBS=`pkg-config --libs gtk+-2.0 gthread-2.0`
 SHL4STDLIBS+=-l$(SHL2TARGET)
-SHL4STDLIBS+=$(SHL3STDLIBS) -lX11 -ldl
-
+  .IF "$(OS)"!="FREEBSD"
+    SHL4STDLIBS+=$(SHL3STDLIBS) -lX11 -ldl
+  .ELSE
+    SHL4STDLIBS+=$(SHL3STDLIBS) -lX11
+  .ENDIF # FREEBSD
 .ENDIF # UNX
 
 # --- Allgemein ----------------------------------------------------------
