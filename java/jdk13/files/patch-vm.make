$FreeBSD$

--- ../../hotspot1.3.1/build/linux/makefiles/vm.make.orig	Tue Oct  7 16:47:45 2003
+++ ../../hotspot1.3.1/build/linux/makefiles/vm.make	Tue Oct  7 16:47:57 2003
@@ -115,7 +115,7 @@
 
 #--billh
 #LIBS += -lnsl -lm -ldl -lpthread
-LIBS = -lm -lc_r
+LIBS = -lm -pthread
 
 JVM = jvm$(G_SUFFIX)
 LIBJVM = lib$(JVM).so
