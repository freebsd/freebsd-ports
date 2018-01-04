--- setup.py.orig	2017-09-29 23:20:39 UTC
+++ setup.py
@@ -409,11 +409,12 @@ elif _platform == "darwin":
     +["examples/OpenGLWindow/MacOpenGLWindowObjC.m"]
 else:
     print("bsd!")
+    libraries = ['GL','GLEW','pthread']
     os.environ['LDFLAGS'] = '-L/usr/X11R6/lib'
     CXX_FLAGS += '-D_BSD '
     CXX_FLAGS += '-I/usr/X11R6/include '
     CXX_FLAGS += '-DHAS_SOCKLEN_T '
-    CXX_FLAGS += '-fno-inline-functions-called-once'
+    #CXX_FLAGS += '-fno-inline-functions-called-once'
     sources = ["examples/ThirdPartyLibs/enet/unix.c"]\
     +["examples/OpenGLWindow/X11OpenGLWindow.cpp"]\
     +["examples/ThirdPartyLibs/Glew/glew.c"]\
