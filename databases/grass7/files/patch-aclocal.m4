--- aclocal.m4.orig	2020-01-25 14:44:25 UTC
+++ aclocal.m4
@@ -560,6 +560,7 @@ AC_DEFUN([SC_CONFIG_CFLAGS], [
 	    # FreeBSD 3.* and greater have ELF.
 	    SHLIB_CFLAGS="-fPIC"
 	    #SHLIB_LD="ld -Bshareable -x"
+            SHLIB_LD_FLAGS="-Wl,-soname,\$(notdir \$[@])"
 	    SHLIB_LD="${CC} -shared"
 	    SHLIB_SUFFIX=".so"
 	    LDFLAGS="-export-dynamic"
