$FreeBSD$

--- ../../hotspot1.3.1/build/linux/makefiles/adlc.make	14 Jan 2002 12:49:49 -0000	1.2
+++ ../../hotspot1.3.1/build/linux/makefiles/adlc.make	22 Nov 2004 17:19:42 -0000
@@ -53,8 +53,8 @@
 #  /usr/dist/share/devpro/5.x-sparc/bin/CC
 #  man -M /usr/dist/share/devpro/5.x-sparc/man CC
 
-CPP       = g++
-CPPFLAGS  = -DASSERT -g -o $@
+CXX       ?= g++
+CXXFLAGS  += -DASSERT -g -o $@
 # -o      object file-name
 # +w      Additional warnings: Nonportable, Likely mistakes or inefficient
 # -xwe    Treat all warnings as errors (skipped for now)
@@ -64,7 +64,7 @@
 # $<      first component of target name
 # $@      target name
 
-CPPFLAGS += ${SYSDEFS} ${INCLUDES}
+CXXFLAGS += ${SYSDEFS} ${INCLUDES}
 
 OBJECTNAMES = \
 	adlparse.o \
@@ -92,7 +92,7 @@
 
 $(EXEC) : $(OBJECTS)
 	@echo Making adlc
-	@$(CPP) $(DFLAGS) $(LFLAGS) $(OBJECTS) -o $(EXEC)
+	@$(CXX) $(DFLAGS) $(LFLAGS) $(OBJECTS) -o $(EXEC)
 
 # The source files refer to ostream.h, which sparcworks calls iostream.h
 $(OBJECTS): ostream.h
@@ -164,7 +164,7 @@
 $(SOURCE.AD): $(SOURCES.AD)
 	@cat $(SOURCES.AD) > $(SOURCE.AD)
 
-COMPILE   = ${CPP} ${CPPFLAGS} ${CFLAGS}
+COMPILE   = ${CXX} ${CXXFLAGS} ${CFLAGS}
 
 COMPILE.o = ${COMPILE} -c
 COMPILE.i = ${COMPILE} -E
