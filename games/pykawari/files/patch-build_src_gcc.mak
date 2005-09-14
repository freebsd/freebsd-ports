--- build/src/gcc.mak.orig	Tue Jun 21 22:28:54 2005
+++ build/src/gcc.mak	Wed Sep 14 10:00:26 2005
@@ -8,14 +8,14 @@
 #==========================================================================
 
 ## choose your target: cygwin, mingw, linux, freebsd, darwin
-MACH_TYPE = mingw
+MACH_TYPE = freebsd
 
 ## output name
 SHIORI = shiori
 
 ## if you have 'upx' and want to use it
 # UPX = upx
-UPX = upx
+
 
 ## if you want to use STLport, set STLport=yes
 # STLport = yes
@@ -24,17 +24,17 @@
 SAORI_NATIVE = yes
 
 ## if you want to use Python SAORI, set SAORI_PYTHON=yes
-# SAORI_PYTHON = yes
+SAORI_PYTHON = yes
 
 ## if you want to use Java SAORI, set SAORI_JAVA=yes
 # SAORI_JAVA = yes
 
 ## if you want to make a Python SHIORI, set SHIORI_PYTHON=yes
-# SHIORI_PYTHON = yes
+SHIORI_PYTHON = yes
 
 ## Global options
-CFLAGS  = -Os -I. -DNDEBUG -Wall -fomit-frame-pointer
-LDFLAGS = -s
+CFLAGS  += -Os -I. -DNDEBUG -Wall -fomit-frame-pointer
+LDFLAGS += -s
 
 #==========================================================================
 # Directories
@@ -96,7 +96,7 @@
 
 ifeq ($(SHIORI_PYTHON),yes)
 	_LINK_PYTHON = 1
-	SHIOSRC := $(SHIOSRC) $(SHIOSRC_python)
+	SHIOSRC := $(SHIOSRC) $(SHIOSRC_PYTHON)
 endif
 
 ifdef _LINK_PYTHON_
@@ -104,7 +104,7 @@
 	ifndef CFLAGS_PYTHON
 		CFLAGS_PYTHON = -I$(shell python -c "import sys; print sys.prefix+'/include/python'+sys.version[:3]")
 		CFLAGS  := $(CFLAGS_PYTHON) $(CFLAGS)
-		LIBS    := $(LIBS) -lpython$(PYTHON_VER)
+		LIBS    := $(LIBS) -L${PYTHONBASE}/lib -l${PYTHON_VERSION}
 	endif
 endif
 
@@ -145,22 +145,23 @@
 ## TARGETS ##
 .PHONY: clean cleanall depend upx
 
-all : $(ALLTARGET) upx
+#all : $(ALLTARGET) 
+all : $(ALLTARGET) $(UPX)
 
 $(MACH)/$(DYNLIBPREFIX)$(SHIORI)$(DYNLIBEXT) : $(SHIOOBJ) $(COREOBJ) $(DEPLIB)
 	$(CXX) -o$@ $(SHARED_$(MACH_TYPE)) $(LDFLAGS) $(SHIOOBJ) $(COREOBJ) $(LIBS)
 
 $(MACH)/kosui$(EXEEXT) : $(KOSUIOBJ) $(COREOBJ) $(DEPLIB)
-	$(CXX) -o$@ $(LDFLAGS) $(KOSUIOBJ) $(COREOBJ) $(LIBS)
+	$(CXX) -o$@ $(LDFLAGS) $(KOSUIOBJ) $(COREOBJ) $(LIBS) ${PTHREAD_LIBS} -lutil
 
 $(MACH)/kawari_encode$(EXEEXT) : tool/kawari_encode$(OBJEXT) $(CRYPTOBJ)
-	$(CXX) -o$@ tool/kawari_encode$(OBJEXT) $(CRYPTOBJ) $(LDFLAGS)
+	$(CXX) -o$@ tool/kawari_encode$(OBJEXT) $(CRYPTOBJ) $(LDFLAGS) ${PTHREAD_LIBS} -lutil
 
 $(MACH)/kawari_encode2$(EXEEXT) : tool/kawari_encode2$(OBJEXT) $(CRYPTOBJ)
-	$(CXX) -o$@ tool/kawari_encode2$(OBJEXT) $(CRYPTOBJ) $(LDFLAGS)
+	$(CXX) -o$@ tool/kawari_encode2$(OBJEXT) $(CRYPTOBJ) $(LDFLAGS) ${PTHREAD_LIBS} -lutil
 
 $(MACH)/kawari_decode2$(EXEEXT) : tool/kawari_decode2$(OBJEXT) $(CRYPTOBJ)
-	$(CXX) -o$@ tool/kawari_decode2$(OBJEXT) $(CRYPTOBJ) $(LDFLAGS)
+	$(CXX) -o$@ tool/kawari_decode2$(OBJEXT) $(CRYPTOBJ) $(LDFLAGS) ${PTHREAD_LIBS} -lutil
 
 $(MACH)/libjvm.dll.a : win32jvm.def
 	dlltool --def win32jvm.def -l $@ --dllname jvm.dll -k -C -a
