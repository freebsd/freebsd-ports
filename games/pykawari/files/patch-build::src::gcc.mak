--- build/src/gcc.mak.orig	Fri Mar 12 20:29:21 2004
+++ build/src/gcc.mak	Fri Mar 12 20:38:29 2004
@@ -6,7 +6,7 @@
 # ターゲットによって書き換え
 
 ## mach type: cygwin, mingw, linux, freebsd, darwin
-MACH_TYPE = linux
+MACH_TYPE = freebsd
 
 ## target name
 SHIORI = shiori
@@ -42,6 +42,7 @@
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
