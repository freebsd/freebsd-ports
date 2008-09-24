--- Makefile.gnu.orig	2008-09-24 22:28:31.000000000 +0200
+++ Makefile.gnu	2008-09-24 22:34:35.000000000 +0200
@@ -4,17 +4,17 @@
 include Makefile.srcs
 
 # General configuration variables:
-CC = gcc
-CXX = g++
+CC ?= gcc
+CXX ?= g++
 AR = ar
 
-INCDIR = /usr/include
-INSTALLDIR = /usr/lib
+INCDIR = %%PREFIX%%/include
+INSTALLDIR = %%PREFIX%%/lib
 
 # Converts cr/lf to just lf
 DOS2UNIX = dos2unix
 
-COMPILERFLAGS = -O3 -fPIC -fexceptions -fvisibility=hidden
+COMPILERFLAGS := ${CFLAGS}
 LIBRARIES = -lstdc++
 
 MODULES = $(SRCS:.c=.o)
@@ -24,7 +24,7 @@
 
 TARGET  = freeimage
 STATICLIB = lib$(TARGET).a
-SHAREDLIB = lib$(TARGET)-$(VER_MAJOR).$(VER_MINOR).so
+SHAREDLIB = lib$(TARGET).so.$(VER_MAJOR)
 LIBNAME	= lib$(TARGET).so
 VERLIBNAME = $(LIBNAME).$(VER_MAJOR)
 HEADER = Source/FreeImage.h
@@ -37,7 +37,7 @@
 
 dist: FreeImage
 	cp *.a Dist
-	cp *.so Dist
+	cp *.so.* Dist
 	cp Source/FreeImage.h Dist
 
 dos2unix:
@@ -58,12 +58,10 @@
 	$(CC) -s -shared -Wl,-soname,$(VERLIBNAME) -o $@ $(MODULES) $(LIBRARIES)
 
 install:
-	install -m 644 -o root -g root $(HEADER) $(INCDIR)
-	install -m 644 -o root -g root $(STATICLIB) $(INSTALLDIR)
-	install -m 755 -o root -g root $(SHAREDLIB) $(INSTALLDIR)
-	ln -sf $(SHAREDLIB) $(INSTALLDIR)/$(VERLIBNAME)
+	install -m 644 -o root -g wheel $(HEADER) $(INCDIR)
+	install -m 644 -o root -g wheel $(STATICLIB) $(INSTALLDIR)
+	install -m 755 -o root -g wheel $(SHAREDLIB) $(INSTALLDIR)
 	ln -sf $(VERLIBNAME) $(INSTALLDIR)/$(LIBNAME)	
-	ldconfig
 
 clean:
 	rm -f core Dist/*.* u2dtmp* $(MODULES) $(STATICLIB) $(SHAREDLIB) $(LIBNAME)
