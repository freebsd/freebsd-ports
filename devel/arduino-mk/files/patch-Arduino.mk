--- Arduino.mk.orig	2011-06-23 06:32:03.000000000 -0700
+++ Arduino.mk	2011-12-28 17:19:57.000000000 -0800
@@ -67,7 +67,7 @@
 #                   this would match the .pde file, but it's not needed
 #                   here: you could always set it to xx if you wanted!
 #    ARDUINO_LIBS - A list of any libraries used by the sketch (we assume
-#                   these are in $(ARDUINO_DIR)/hardware/libraries
+#                   these are in $(ARDUINO_DIR)/libraries
 #    ARDUINO_PORT - The port where the Arduino can be found (only needed
 #                   when uploading
 #    BOARD_TAG    - The ard-parse-boards tag for the board e.g. uno or mega
@@ -155,6 +155,7 @@
 
 ARDUINO_LIB_PATH  = $(ARDUINO_DIR)/libraries
 ARDUINO_CORE_PATH = $(ARDUINO_DIR)/hardware/arduino/cores/arduino
+ARDUINO_VARIANT_PATH = $(ARDUINO_DIR)/hardware/arduino/variants/$(VARIANT)
 
 endif
 
@@ -170,7 +171,7 @@
 endif
 
 ifndef PARSE_BOARD
-PARSE_BOARD = ard-parse-boards --boards_txt=$(BOARDS_TXT)
+PARSE_BOARD = $(ARDUINO_DIR)/tools/ard-parse-boards --boards_txt=$(BOARDS_TXT)
 endif
 
 # processor stuff
@@ -182,6 +183,10 @@
 F_CPU = $(shell $(PARSE_BOARD) $(BOARD_TAG) build.f_cpu)
 endif
 
+ifndef VARIANT
+VARIANT = $(shell $(PARSE_BOARD) $(BOARD_TAG) build.variant)
+endif
+
 # normal programming info
 ifndef AVRDUDE_ARD_PROGRAMMER
 AVRDUDE_ARD_PROGRAMMER = $(shell $(PARSE_BOARD) $(BOARD_TAG) upload.protocol)
@@ -221,11 +226,11 @@
 ########################################################################
 # Local sources
 #
-LOCAL_C_SRCS    = $(wildcard *.c)
-LOCAL_CPP_SRCS  = $(wildcard *.cpp)
-LOCAL_CC_SRCS   = $(wildcard *.cc)
-LOCAL_PDE_SRCS  = $(wildcard *.pde)
-LOCAL_AS_SRCS   = $(wildcard *.S)
+LOCAL_C_SRCS   ?= $(wildcard *.c)
+LOCAL_CPP_SRCS ?= $(wildcard *.cpp)
+LOCAL_CC_SRCS  ?= $(wildcard *.cc)
+LOCAL_PDE_SRCS ?= $(wildcard *.pde)
+LOCAL_AS_SRCS  ?= $(wildcard *.S)
 LOCAL_OBJ_FILES = $(LOCAL_C_SRCS:.c=.o) $(LOCAL_CPP_SRCS:.cpp=.o) \
 		$(LOCAL_CC_SRCS:.cc=.o) $(LOCAL_PDE_SRCS:.pde=.o) \
 		$(LOCAL_AS_SRCS:.S=.o)
@@ -278,10 +283,14 @@
 SYS_INCLUDES  = $(patsubst %,-I%,$(SYS_LIBS))
 SYS_OBJS      = $(wildcard $(patsubst %,%/*.o,$(SYS_LIBS)))
 LIB_SRC       = $(wildcard $(patsubst %,%/*.cpp,$(SYS_LIBS)))
-LIB_OBJS      = $(patsubst $(ARDUINO_LIB_PATH)/%.cpp,$(OBJDIR)/libs/%.o,$(LIB_SRC))
-
-CPPFLAGS      = -mmcu=$(MCU) -DF_CPU=$(F_CPU) \
-			-I. -I$(ARDUINO_CORE_PATH) \
+LIB_SRC2      = $(wildcard $(patsubst %,%/*.c,$(SYS_LIBS)))
+LIB_OBJS      = $(patsubst $(ARDUINO_LIB_PATH)/%.cpp,$(OBJDIR)/libs/%.o,$(LIB_SRC)) \
+		$(patsubst $(ARDUINO_LIB_PATH)/%.c,$(OBJDIR)/libs/%.o,$(LIB_SRC2))
+
+ARDUINO = %%ARDUINO%%
+CPPFLAGS      = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=$(ARDUINO) \
+			-D__DELAY_BACKWARD_COMPATIBLE__ \
+			-I. -I$(ARDUINO_CORE_PATH) -I$(ARDUINO_VARIANT_PATH) \
 			$(SYS_INCLUDES) -g -Os -w -Wall \
 			-ffunction-sections -fdata-sections
 CFLAGS        = -std=gnu99
@@ -289,8 +298,9 @@
 ASFLAGS       = -mmcu=$(MCU) -I. -x assembler-with-cpp
 LDFLAGS       = -mmcu=$(MCU) -lm -Wl,--gc-sections -Os
 
-# Rules for making a CPP file from the main sketch (.cpe)
-PDEHEADER     = \\\#include \"WProgram.h\"
+# Rules for making a CPP file from the main sketch (.pde)
+NEWPDEHEADER     = \\\#include \"Arduino.h\"
+OLDPDEHEADER     = \\\#include \"WProgram.h\"
 
 # Expand and pick the first port
 ARD_PORT      = $(firstword $(wildcard $(ARDUINO_PORT)))
@@ -308,6 +318,10 @@
 	mkdir -p $(dir $@)
 	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@
 
+$(OBJDIR)/libs/%.o: $(ARDUINO_LIB_PATH)/%.c
+	mkdir -p $(dir $@)
+	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@
+
 # normal local sources
 # .o rules are for objects, .d for dependency tracking
 # there seems to be an awful lot of duplication here!!!
@@ -343,7 +357,11 @@
 
 # the pde -> cpp -> o file
 $(OBJDIR)/%.cpp: %.pde
-	$(ECHO) $(PDEHEADER) > $@
+	$(ECHO) \#if $(ARDUINO) \>= 100 > $@
+	$(ECHO) $(NEWPDEHEADER) >> $@
+	$(ECHO) \#else >> $@
+	$(ECHO) $(OLDPDEHEADER) >> $@
+	$(ECHO) \#endif >> $@
 	$(CAT)  $< >> $@
 
 $(OBJDIR)/%.o: $(OBJDIR)/%.cpp
