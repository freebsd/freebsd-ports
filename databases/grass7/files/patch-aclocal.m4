--- aclocal.m4.orig	2020-12-21 18:40:15 UTC
+++ aclocal.m4
@@ -560,10 +560,11 @@ AC_DEFUN([SC_CONFIG_CFLAGS], [
 	    # FreeBSD 3.* and greater have ELF.
 	    SHLIB_CFLAGS="-fPIC"
 	    #SHLIB_LD="ld -Bshareable -x"
+            SHLIB_LD_FLAGS="-Wl,-soname,\$(notdir \$[@])"
 	    SHLIB_LD="${CC} -shared"
             SHLIB_LD_FLAGS="-Wl,-soname,\$(notdir \$[@])"
 	    SHLIB_SUFFIX=".so"
-	    LDFLAGS="-export-dynamic"
+	    LDFLAGS="-Wl,--export-dynamic"
 	    #LD_SEARCH_FLAGS='-rpath ${LIB_RUNTIME_DIR}'
 	    LD_SEARCH_FLAGS='-Wl,-rpath-link,${LIB_RUNTIME_DIR}'
 	    # TODO: add optional pthread support with any combination of: 
