--- setup.py.orig	2018-12-31 20:42:41 UTC
+++ setup.py
@@ -535,7 +535,7 @@ else:
     CXX_FLAGS += '-D_BSD '
     CXX_FLAGS += '-I/usr/X11R6/include '
     CXX_FLAGS += '-DHAS_SOCKLEN_T '
-    CXX_FLAGS += '-fno-inline-functions-called-once'
+    #CXX_FLAGS += '-fno-inline-functions-called-once'
     sources = ["examples/ThirdPartyLibs/enet/unix.c"]\
     +["examples/OpenGLWindow/X11OpenGLWindow.cpp"]\
     +["examples/ThirdPartyLibs/glad/gl.c"]\
