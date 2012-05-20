--- src/src.pro	2009/12/15 17:10:52	64
+++ src/src.pro	2012/04/03 22:32:00	74
@@ -154,6 +154,10 @@
     LIBS += -lshell32
 }
 
+unix {
+    LIBS += -lGLU
+}
+
 MOC_DIR = ../tmp
 RCC_DIR = ../tmp
 UI_DIR = ../tmp
