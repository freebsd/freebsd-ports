$FreeBSD$

--- ../../hotspot1.3.1/build/linux/makefiles/vm.make	23 Jul 2004 18:17:54 -0000	1.7
+++ ../../hotspot1.3.1/build/linux/makefiles/vm.make	22 Nov 2004 17:19:42 -0000
@@ -62,7 +62,7 @@
 BUILD_VERSION = -DHOTSPOT_BUILD_VERSION="\"$(HOTSPOT_BUILD_VERSION)\""
 BUILD_VERSION$(HOTSPOT_BUILD_VERSION) = 
 
-CPPFLAGS = ${SYSDEFS} ${INCLUDES} ${BUILD_VERSION}
+CXXFLAGS += ${SYSDEFS} ${INCLUDES} ${BUILD_VERSION}
 
 # Suppress warnings (for now)
 CFLAGS += -w
@@ -70,9 +70,9 @@
 # do not include shared lib path in a.outs
 #AOUT_FLAGS += -norunpath
 
-COMPILE   = ${CPP} ${CPPFLAGS} ${CFLAGS}
-LINK_LIB  = ${CPP} -shared -mimpure-text
-LINK      = ${CPP} ${AOUT_FLAGS}
+COMPILE   = ${CXX} ${CXXFLAGS} ${CFLAGS}
+LINK_LIB  = ${CXX} -shared -mimpure-text
+LINK      = ${CXX} ${AOUT_FLAGS}
 
 
 COMPILE.s = ${COMPILE} -S
@@ -157,7 +157,7 @@
 LAUNCHER = $(GAMMADIR)/src/os/$(Platform_os_family)/launcher
 LAUNCHERFLAGS = -I$(LAUNCHER) -I$(GAMMADIR)/src/share/vm/prims
 launcher.o: launcher.c $(LAUNCHER)/java.c $(LAUNCHER)/java_md.c
-	$(CC) -g -c -o $@ launcher.c $(LAUNCHERFLAGS) $(CPPFLAGS)
+	$(CC) -g -c -o $@ launcher.c $(LAUNCHERFLAGS) $(CXXFLAGS)
 
 # Figure out how to turn this off:
 #LAUNCHERFLAGS += -DOLDJAVA
