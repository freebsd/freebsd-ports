$FreeBSD$

author:  Tod McQuillin

--- speech_tools/config/rules/install.mak~	Sun May 30 22:51:10 1999
+++ speech_tools/config/rules/install.mak	Wed Mar  9 03:11:35 2005
@@ -39,7 +39,7 @@
 
 
 
-PROJECT_HOME_PATH := $(shell mkdir -p $($(PROJECT_PREFIX)_HOME); cd $($(PROJECT_PREFIX)_HOME); pwd)
+PROJECT_HOME_PATH := $($(PROJECT_PREFIX)_HOME)
 
 PROJECT_TOP_PATH := $(shell (cd $(TOP); pwd))
 
