--- Arduino.mk.orig	2012-02-12 09:19:53.000000000 -0800
+++ Arduino.mk	2012-08-04 23:47:14.000000000 -0700
@@ -92,7 +92,7 @@
 #
 #    ARDUINO_LIBS - A list of any libraries used by the sketch (we
 #                   assume these are in
-#                   $(ARDUINO_DIR)/hardware/libraries 
+#                   $(ARDUINO_DIR)/libraries 
 #
 #    ARDUINO_PORT - The port where the Arduino can be found (only needed
 #                   when uploading
@@ -176,7 +176,7 @@
 #
 # Arduino version number
 ifndef ARDUINO_VERSION
-ARDUINO_VERSION = 100
+ARDUINO_VERSION = %%ARDUINO%%
 endif
 
 #
@@ -215,7 +215,7 @@
 endif
 
 ifndef PARSE_BOARD
-PARSE_BOARD = ard-parse-boards --boards_txt=$(BOARDS_TXT)
+PARSE_BOARD = $(ARDUINO_DIR)/tools/ard-parse-boards --boards_txt=$(BOARDS_TXT)
 endif
 
 # Which variant ? This affects the include path
@@ -268,12 +268,12 @@
 ########################################################################
 # Local sources
 #
-LOCAL_C_SRCS    = $(wildcard *.c)
-LOCAL_CPP_SRCS  = $(wildcard *.cpp)
-LOCAL_CC_SRCS   = $(wildcard *.cc)
-LOCAL_PDE_SRCS  = $(wildcard *.pde)
-LOCAL_INO_SRCS  = $(wildcard *.ino)
-LOCAL_AS_SRCS   = $(wildcard *.S)
+LOCAL_C_SRCS    ?= $(wildcard *.c)
+LOCAL_CPP_SRCS  ?= $(wildcard *.cpp)
+LOCAL_CC_SRCS   ?= $(wildcard *.cc)
+LOCAL_PDE_SRCS  ?= $(wildcard *.pde)
+LOCAL_INO_SRCS  ?= $(wildcard *.ino)
+LOCAL_AS_SRCS   ?= $(wildcard *.S)
 LOCAL_OBJ_FILES = $(LOCAL_C_SRCS:.c=.o)   $(LOCAL_CPP_SRCS:.cpp=.o) \
 		$(LOCAL_CC_SRCS:.cc=.o)   $(LOCAL_PDE_SRCS:.pde=.o) \
 		$(LOCAL_INO_SRCS:.ino=.o) $(LOCAL_AS_SRCS:.S=.o)
@@ -392,7 +392,11 @@
 
 # the pde -> cpp -> o file
 $(OBJDIR)/%.cpp: %.pde
-	$(ECHO) '#include "WProgram.h"' > $@
+	$(ECHO) '#if ARDUINO >= 100' > $@
+	$(ECHO) '#include "Arduino.h"' >> $@
+	$(ECHO) '#else' >> $@
+	$(ECHO) '#include "WProgram.h"' >> $@
+	$(ECHO) '#endif' >> $@
 	$(CAT)  $< >> $@
 
 # the ino -> cpp -> o file
