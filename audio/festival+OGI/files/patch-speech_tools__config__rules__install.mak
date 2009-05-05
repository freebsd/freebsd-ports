--- speech_tools/config/rules/install.mak.orig	Sun May 30 10:51:10 1999
+++ speech_tools/config/rules/install.mak	Sun Oct 29 20:50:07 2006
@@ -39,8 +39,6 @@
 
 
 
-PROJECT_HOME_PATH := $(shell mkdir -p $($(PROJECT_PREFIX)_HOME); cd $($(PROJECT_PREFIX)_HOME); pwd)
-
 PROJECT_TOP_PATH := $(shell (cd $(TOP); pwd))
 
 S = _static
