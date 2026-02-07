- use system zlib because of SEGV: https://github.com/bulletphysics/bullet3/issues/3280

--- setup.py.orig	2021-02-22 06:17:11 UTC
+++ setup.py
@@ -160,21 +160,6 @@ sources = ["examples/pybullet/pybullet.c"]\
 +["examples/ThirdPartyLibs/minizip/ioapi.c"]\
 +["examples/ThirdPartyLibs/minizip/unzip.c"]\
 +["examples/ThirdPartyLibs/minizip/zip.c"]\
-+["examples/ThirdPartyLibs/zlib/adler32.c"]\
-+["examples/ThirdPartyLibs/zlib/compress.c"]\
-+["examples/ThirdPartyLibs/zlib/crc32.c"]\
-+["examples/ThirdPartyLibs/zlib/deflate.c"]\
-+["examples/ThirdPartyLibs/zlib/gzclose.c"]\
-+["examples/ThirdPartyLibs/zlib/gzlib.c"]\
-+["examples/ThirdPartyLibs/zlib/gzread.c"]\
-+["examples/ThirdPartyLibs/zlib/gzwrite.c"]\
-+["examples/ThirdPartyLibs/zlib/infback.c"]\
-+["examples/ThirdPartyLibs/zlib/inffast.c"]\
-+["examples/ThirdPartyLibs/zlib/inflate.c"]\
-+["examples/ThirdPartyLibs/zlib/inftrees.c"]\
-+["examples/ThirdPartyLibs/zlib/trees.c"]\
-+["examples/ThirdPartyLibs/zlib/uncompr.c"]\
-+["examples/ThirdPartyLibs/zlib/zutil.c"]\
 +["examples/Importers/ImportColladaDemo/LoadMeshFromCollada.cpp"]\
 +["examples/Importers/ImportObjDemo/LoadMeshFromObj.cpp"]\
 +["examples/Importers/ImportObjDemo/Wavefront2GLInstanceGraphicsShape.cpp"]\
@@ -438,7 +423,7 @@ elif _platform == "darwin":
   +["examples/OpenGLWindow/MacOpenGLWindowObjC.m"]
 else:
   print("bsd!")
-  libraries = ['GL', 'GLEW', 'pthread']
+  libraries = ['GL', 'GLEW', 'pthread', 'z']
   os.environ['LDFLAGS'] = '-L/usr/X11R6/lib'
   CXX_FLAGS += '-D_BSD '
   CXX_FLAGS += '-I/usr/X11R6/include '
