--- Makefile.mk.orig	2016-01-25 10:55:48 UTC
+++ Makefile.mk
@@ -3,8 +3,8 @@
 CC ?= gcc
 
 # flags
-CFLAGS += -O3 -funroll-loops -ffast-math -fomit-frame-pointer -fstrength-reduce -Wall -Werror -fPIC -DPIC -I../utils
-LDFLAGS += -shared -Wl,-O1 -Wl,--as-needed -Wl,--no-undefined -Wl,--strip-all -lm -lrt
+CFLAGS += -funroll-loops -ffast-math -fomit-frame-pointer -Wall -Werror -fPIC -DPIC -I../utils
+LDFLAGS += -shared -Wl,--as-needed -Wl,--no-undefined -lm -lrt
 
 ifneq ($(NOOPT),true)
 CFLAGS += -mtune=generic -msse -msse2 -mfpmath=sse
