--- ./defaults.make.orig	2008-06-28 23:24:06.000000000 +0900
+++ ./defaults.make	2008-07-17 01:19:10.000000000 +0900
@@ -47,6 +47,7 @@
 PREFIX ?= c:/devtools
 else
 PREFIX ?= /usr/local
+LOCALBASE ?= /usr/local
 endif
 endif
 
@@ -146,8 +147,8 @@
 # options
 
 ifneq ($(USE_HOST_PCRE),)
-LIBRARIES += -lpcre
-PCRE_INCLUDES =
+LIBRARIES += -L$(LOCALBASE)/lib -lpcre
+PCRE_INCLUDES = -I$(LOCALBASE)/include
 C_COMPILER_PCRE_OPTIONS =
 PCRE_OBJECTS_1 =
 else
