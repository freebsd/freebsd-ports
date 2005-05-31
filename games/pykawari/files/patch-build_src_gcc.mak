--- build/src/gcc.mak.orig	Sat Aug 28 19:16:34 2004
+++ build/src/gcc.mak	Sat Oct  2 15:26:37 2004
@@ -6,21 +6,21 @@
 # ターゲットによって書き換え
 
 ## mach type: cygwin, mingw, linux, freebsd, darwin
-MACH_TYPE = mingw
+MACH_TYPE = freebsd
 
 ## target name
 SHIORI = shiori
 
 ## if use STLport, set STLport=yes
-STLport = yes
+# STLport = yes
 
 # (STLport) specify library include directory.
-STLP_CFLAGS = -I/MinGW/include/stlport
-STLP_LIBS = -lstlport_mingw32_static
+# STLP_CFLAGS = -I/MinGW/include/stlport
+# STLP_LIBS = -lstlport_mingw32_static
 ## fi
 
 ## if you have 'upx'
-UPX = upx
+# UPX = upx
 
 #==========================================================================
 # EXPERIMENTAL FEATURES
@@ -37,11 +37,12 @@
 ## fi
 
 ## if use Python SAORI(and Python I/F), set PYTHON=yes
-#PYTHON = yes
+PYTHON = yes
 
 ## (Python) and if win32
 # PYTHON_CFLAGS = -I/python22jp/include
 # PYTHON_LIBS = -L/python22jp/libs
+PYTHON_LIBS = -L${PYTHONBASE}/lib/${PYTHON_VERSION}/config -l${PYTHON_VERSION}
 
 #==========================================================================
 # 以下、基本的に書き換え不要
@@ -146,19 +147,19 @@
 	$(CXX) -o $@ -bundle $(SHIOOBJ) $(LIBOBJ) $(LDFLAGS)
 
 $(MACH)/kosui$(EXEEXT) : $(KOSUIOBJ) $(LIBOBJ)
-	$(CXX) -o $@ $(KOSUIOBJ) $(LIBOBJ) $(LDFLAGS)
+	$(CXX) -o $@ $(KOSUIOBJ) $(LIBOBJ) $(LDFLAGS) ${PTHREAD_LIBS} -lutil
 	$(STRIP) $@
 
 $(MACH)/kawari_encode$(EXEEXT) : tool/kawari_encode$(OBJEXT) $(CRYPTOBJ)
-	$(CXX) -o $@ tool/kawari_encode$(OBJEXT) $(CRYPTOBJ) $(LDFLAGS)
+	$(CXX) -o $@ tool/kawari_encode$(OBJEXT) $(CRYPTOBJ) $(LDFLAGS) ${PTHREAD_LIBS}
 	$(STRIP) $@
 
 $(MACH)/kawari_encode2$(EXEEXT) : tool/kawari_encode2$(OBJEXT) $(CRYPTOBJ)
-	$(CXX) -o $@ tool/kawari_encode2$(OBJEXT) $(CRYPTOBJ) $(LDFLAGS)
+	$(CXX) -o $@ tool/kawari_encode2$(OBJEXT) $(CRYPTOBJ) $(LDFLAGS) ${PTHREAD_LIBS}
 	$(STRIP) $@
 
 $(MACH)/kawari_decode2$(EXEEXT) : tool/kawari_decode2$(OBJEXT) $(CRYPTOBJ)
-	$(CXX) -o $@ tool/kawari_decode2$(OBJEXT) $(CRYPTOBJ) $(LDFLAGS)
+	$(CXX) -o $@ tool/kawari_decode2$(OBJEXT) $(CRYPTOBJ) $(LDFLAGS) ${PTHREAD_LIBS}
 	$(STRIP) $@
 
 .SUFFIXES : .cpp .h
