--- misc/deplib.sh.orig	Thu Jul  4 05:18:01 2002
+++ misc/deplib.sh	Tue Nov  5 22:56:54 2002
@@ -10,7 +10,7 @@
     staticlib="lib${1}.a"
     staticobj="\$(${2}_OBJECTS)"
 
-    sharelib="lib${1}-\$(shared_version).so"
+    sharelib="lib${1}.so.\$(shared_version)"
     shareobj="\$(${2}_SHARED_OBJECTS)"
 
     unsharelib="lib${1}_unsharable.a"
@@ -24,7 +24,7 @@
     echo "	rm -f \$@"
     # gf: This bit is obviously gcc-specific
     # eb: Yes, but the GNU C Compiler doesn't always spell 'gcc'
-    echo "	\$(CC) -shared -o \$@ ${shareobj} \$(LDFLAGS) -Wl,-soname,lib${1}.so.\$(shared_major_minor) \$(LIBS)"
+    echo "	\$(CC) -shared -o \$@ ${shareobj} \$(LDFLAGS) -Wl,-soname,lib${1}.so.\$(shared_version) \$(LIBS)"
     echo ""
     echo "\$(LIBDIR)/${unsharelib}: ${unshareobj}"
     echo "	rm -f \$@"
