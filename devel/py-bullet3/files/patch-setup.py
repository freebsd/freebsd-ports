--- setup.py.orig	2020-01-04 10:04:32 UTC
+++ setup.py
@@ -434,7 +434,7 @@ else:
   CXX_FLAGS += '-D_BSD '
   CXX_FLAGS += '-I/usr/X11R6/include '
   CXX_FLAGS += '-DHAS_SOCKLEN_T '
-  CXX_FLAGS += '-fno-inline-functions-called-once'
+  #CXX_FLAGS += '-fno-inline-functions-called-once'
   sources = ["examples/ThirdPartyLibs/enet/unix.c"]\
   +["examples/OpenGLWindow/X11OpenGLWindow.cpp"]\
   +["examples/ThirdPartyLibs/glad/gl.c"]\
