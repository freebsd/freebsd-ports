--- build/src/gcc.mak.orig	Thu Jan 22 07:47:30 2004
+++ build/src/gcc.mak	Thu Jan 22 07:49:18 2004
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
@@ -146,7 +147,7 @@
 	$(CXX) -o $@ -bundle $(SHIOOBJ) $(LIBOBJ) $(LDFLAGS)
 
 $(MACH)/kosui$(EXEEXT) : $(KOSUIOBJ) $(LIBOBJ)
-	$(CXX) -o $@ $(KOSUIOBJ) $(LIBOBJ) $(LDFLAGS)
+	$(CXX) -o $@ $(KOSUIOBJ) $(LIBOBJ) $(LDFLAGS) ${PTHREAD_LIBS} -lutil
 	$(STRIP) $@
 
 $(MACH)/kawari_encode$(EXEEXT) : tool/kawari_encode$(OBJEXT) $(CRYPTOBJ)
