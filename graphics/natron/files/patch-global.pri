--- global.pri.orig	2017-08-13 15:26:35 UTC
+++ global.pri
@@ -308,18 +308,20 @@ unix {
      expat:     PKGCONFIG += expat
 
      # GLFW will require a link to X11 on linux and OpenGL framework on OS X
-     linux-* {
+     linux-*|freebsd-* {
           LIBS += -lGL -lX11
          # link with static cairo on linux, to avoid linking to X11 libraries in NatronRenderer
          cairo {
              PKGCONFIG += pixman-1 freetype2 fontconfig
              LIBS +=  $$system(pkg-config --variable=libdir cairo)/libcairo.a
          }
-         LIBS += -ldl
          QMAKE_LFLAGS += '-Wl,-rpath,\'\$$ORIGIN/../lib\',-z,origin'
      } else {
          LIBS += -framework OpenGL
          cairo:     PKGCONFIG += cairo
+     }
+     linux-* {
+         LIBS += -ldl
      }
 
      # User may specify an alternate python2-config from the command-line,
