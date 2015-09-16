--- Qt/Platform/linux.pri.orig	2015-02-26 20:05:06 UTC
+++ Qt/Platform/linux.pri
@@ -6,7 +6,8 @@
 	}
 
 	# Executable
-	LIBS += -ldl -lrt
+	LIBS += $$QMAKE_LIBS_DYNLOAD # dlopen
+	linux-*|hpux-*|solaris-*: LIBS += -lrt # clock_gettime
 
 	# Packaging
 	icon16.files = $$P/assets/unix-icons/hicolor/16x16/apps/ppsspp.png
