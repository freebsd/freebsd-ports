--- misc/deplib.sh.orig	Sun Nov  9 19:43:07 2003
+++ misc/deplib.sh	Thu Dec 11 22:32:16 2003
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
-    echo "	\$(CC) -shared -o \$@ ${shareobj} ${3} \$(LDFLAGS) -Wl,-h,lib${1}.so.\$(shared_major_minor) \$(LIBS)"
+    echo "	\$(CC) -shared -o \$@ ${shareobj} \$(LDFLAGS) -Wl,-h,lib${1}.so.\$(shared_version) \$(LIBS)"
     echo ""
     echo "\$(LIBDIR)/${unsharelib}: ${unshareobj}"
     echo "	rm -f \$@"
