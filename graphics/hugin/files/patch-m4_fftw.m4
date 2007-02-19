--- m4/ax_fftw.m4.orig	Wed Jan 17 15:31:31 2007
+++ m4/ax_fftw.m4	Wed Jan 17 15:32:36 2007
@@ -12,7 +12,7 @@
             AC_HELP_STRING([--with-fftw=DIR],
                            [where the root of FFTW is installed ]),
     [  ac_fftw_includes="$withval"/include
-	   if test "x$HCPU" = 'xamd64' ; then
+	   if test "x$HCPU" = 'xamd64' -a "x$HSYS" != 'xfreebsd' ; then
          ac_fftw_libraries="$withval"/lib64
 	   else
          ac_fftw_libraries="$withval"/lib
@@ -45,12 +45,12 @@
 AC_FIND_FILE(fftw.h, $fftw_incdirs, fftw_incdir)
 ac_fftw_includes="$fftw_incdir"
 
-if test "x$HCPU" = 'xamd64' ; then
+if test "x$HCPU" = 'xamd64' -a "x$HSYS" != 'xfreebsd' ; then
   fftw_libdirs="/usr/lib64/fftw/lib64 /usr/lib64 /opt/lib64 /mingw/lib64 /usr/local/fftw/lib64 /usr/local/lib64 /usr/lib64/fftw $FFTWLIB"
 else
   fftw_libdirs="/usr/lib/fftw/lib /usr/lib /opt/lib /mingw/lib /usr/local/fftw/lib /usr/local/lib /usr/lib/fftw $FFTWLIB"
 fi
-if test "x$HCPU" = 'xamd64' ; then
+if test "x$HCPU" = 'xamd64' -a "x$HSYS" != 'xfreebsd' ; then
   test -n "$FFTWDIR" && fftw_libdirs="$FFTWDIR/lib64 $FFTWDIR $fftw_libdirs"
 else
   test -n "$FFTWDIR" && fftw_libdirs="$FFTWDIR/lib $FFTWDIR $fftw_libdirs"
