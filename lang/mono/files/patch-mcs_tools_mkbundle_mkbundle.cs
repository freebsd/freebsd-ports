--- mcs/tools/mkbundle/mkbundle.cs.orig	Wed Jul  5 17:57:12 2006
+++ mcs/tools/mkbundle/mkbundle.cs	Sat Sep  9 11:46:36 2006
@@ -354,7 +354,7 @@
 					smonolib = "`pkg-config --variable=libdir mono`/libmono.a ";
 				else
 					smonolib = "-Wl,-Bstatic -lmono -Wl,-Bdynamic ";
-				cmd = String.Format ("{4} -o {2} -Wall `pkg-config --cflags mono` {0} {3} " +
+				cmd = String.Format ("{4} -o {2} -pthread -Wall `pkg-config --cflags mono` {0} {3} " +
 						     "`pkg-config --libs-only-L mono` " + smonolib +
 						     "`pkg-config --libs-only-l mono | sed -e \"s/\\-lmono //\"` {1}",
 						     temp_c, temp_o, output, zlib, cc);
