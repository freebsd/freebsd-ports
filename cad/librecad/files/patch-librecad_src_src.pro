FreeBSD needs to link to -lexecinfo to define backtrace(3) symbols.

--- librecad/src/src.pro.orig	2026-05-02 02:15:08 UTC
+++ librecad/src/src.pro
@@ -85,6 +85,9 @@ else:unix {
 else:unix {
     # lc_crashhandler: export symbols so backtrace_symbols() can resolve them
     QMAKE_LFLAGS += -rdynamic
+    freebsd {
+        LIBS += -lexecinfo
+    }
 }
 
 DEFINES += LC_VERSION=\"$$LC_VERSION\"
