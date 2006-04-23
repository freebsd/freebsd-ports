--- mcs/tools/mkbundle/mkbundle.cs.orig	Mon Mar 13 17:58:04 2006
+++ mcs/tools/mkbundle/mkbundle.cs	Mon Apr 17 23:02:10 2006
@@ -337,7 +337,7 @@
 					smonolib = "`pkg-config --variable=libdir mono`/libmono.a ";
 				else
 					smonolib = "-Wl,-Bstatic -lmono -Wl,-Bdynamic ";
-				cmd = String.Format ("cc -o {2} -Wall `pkg-config --cflags mono` {0} {3}" +
+				cmd = String.Format ("%%CC%% -o {2} %%PTHREAD_LIBS%% -Wall `pkg-config --cflags mono` {0} {3}" +
 						     "`pkg-config --libs-only-L mono` " + smonolib +
 						     "`pkg-config --libs-only-l mono | sed -e \"s/\\-lmono //\"` {1}",
 						     temp_c, temp_o, output, zlib);
