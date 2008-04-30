--- qfsm.pro.bak	2008-04-04 16:40:05.000000000 +0900
+++ qfsm.pro	2008-04-05 14:03:47.000000000 +0900
@@ -3,7 +3,7 @@
 
 VERSION = 0.50
 
-CONFIG	+= debug
+#CONFIG	+= debug
 
 INCLUDEPATH	+= . src
 
@@ -200,7 +200,7 @@
 #  INSTDIR = $${PROGRAMFILES}
   INSTDIR = "C:\Qfsm"
 } else {
-  INSTDIR = /usr
+  INSTDIR = %%PREFIX%%
 }
 DEPENDPATH += po src 
 TARGET = qfsm
@@ -212,7 +212,7 @@
   DEFINES += QFSM_HELP_DIR=\\\"doc\\user\\\"
 } else {
   DEFINES += QFSM_LANGUAGE_DIR=\\\"$${INSTDIR}/share/qfsm\\\"
-  DEFINES += QFSM_HELP_DIR=\\\"${INSTDIR}/share/doc/qfsm\\\")
+  DEFINES += QFSM_HELP_DIR=\\\"$${INSTDIR}/share/doc/qfsm\\\"
 }
 
 # XPMS = $$system( find pics -type f -name "*.xpm" | grep -v CVS )
@@ -359,7 +359,7 @@
   trans.path = $${INSTDIR}/share/qfsm
   trans.files = $$QMS
 
-  INSTALLS += target doc trans desktop mime icons 
+  INSTALLS += target trans desktop mime icons 
 }
 
 
