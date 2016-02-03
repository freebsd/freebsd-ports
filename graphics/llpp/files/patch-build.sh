--- build.sh.orig	2015-10-13 20:12:27 UTC
+++ build.sh
@@ -7,8 +7,8 @@ else
     builddir="$1"
 fi
 
-ccopt='-Wno-pointer-sign -O2'
-mlopt='-warn-error +a -w +a -g -safe-string'
+ccopt='-Wno-pointer-sign -I${LOCALBASE}/include'
+mlopt='-warn-error +a -w +a -safe-string'
 if test -z "$native"; then
     comp=ocamlc.opt
     osu=.cmo
@@ -22,13 +22,13 @@ else
 fi
 mkdir -p "$builddir/lablGL"
 srcdir=$(dirname $0)
-version=$(cd $srcdir && git describe --tags 2>/dev/null) || version=unknown
+version="v${PORTVERSION}"
 mloptgl="-I $srcdir/lablGL -I $builddir/lablGL"
 set -x
 $comp -ccopt "$ccopt -o $builddir/lablGL/ml_raw.o" -c $srcdir/lablGL/ml_raw.c
 $comp -ccopt "$ccopt -o $builddir/lablGL/ml_gl.o" -c $srcdir/lablGL/ml_gl.c
 $comp -ccopt "$ccopt -o $builddir/lablGL/ml_glarray.o" -c $srcdir/lablGL/ml_glarray.c
-$comp -ccopt "-I $srcdir/mupdf/include -I $srcdir/mupdf/thirdparty/freetype/include -Wextra -Wall -Werror -D_GNU_SOURCE -O -g -std=c99 -pedantic-errors -Wunused-parameter -Wsign-compare -Wshadow -o $builddir/link.o" -c $srcdir/link.c
+$comp -ccopt "-I${LOCALBASE}/include/freetype2 -I${LOCALBASE}/include -Wextra -Wall -Wno-variadic-macros -D_GNU_SOURCE -std=c99 -pedantic-errors -Wunused-parameter -Wsign-compare -Wshadow -o $builddir/link.o" -c $srcdir/link.c
 /bin/sh $srcdir/mkhelp.sh $srcdir/KEYS "$version" >$builddir/help.ml
 $comp -c $mloptgl -o $builddir/lablGL/gl$osu $srcdir/lablGL/gl.ml
 $comp -c $mloptgl -o $builddir/lablGL/raw$osu $srcdir/lablGL/raw.ml
@@ -50,4 +50,4 @@ $comp -c $mloptgl -I $builddir -o $build
 sed -f $srcdir/pp.sed $srcdir/main.ml >$builddir/main.ml
 $comp -c $mloptgl -I $builddir -o $builddir/main$osu $builddir/main.ml
 $comp -c $mlopt -I $builddir -o $builddir/wsi$osu $srcdir/wsi.ml
-$comp -g $lfl -I lablGL -o $builddir/llpp unix$asu str$asu $builddir/help$osu $builddir/lablGL/raw$osu $builddir/utils$osu $builddir/parser$osu $builddir/lablGL/glMisc$osu $builddir/wsi$osu $builddir/lablGL/gl$osu $builddir/lablGL/glMat$osu $builddir/lablGL/glFunc$osu $builddir/lablGL/glClear$osu $builddir/lablGL/glPix$osu $builddir/lablGL/glTex$osu $builddir/lablGL/glDraw$osu $builddir/config$osu $builddir/lablGL/glArray$osu $builddir/main$osu $builddir/link.o -cclib "-lGL -lX11 -lmupdf -lz -lfreetype -ljpeg -ljbig2dec -lopenjpeg -lmujs -lpthread -L$srcdir/mupdf/build/native -lcrypto $builddir/lablGL/ml_gl.o $builddir/lablGL/ml_glarray.o $builddir/lablGL/ml_raw.o"
+$comp $lfl -I lablGL -o $builddir/llpp unix$asu str$asu $builddir/help$osu $builddir/lablGL/raw$osu $builddir/utils$osu $builddir/parser$osu $builddir/lablGL/glMisc$osu $builddir/wsi$osu $builddir/lablGL/gl$osu $builddir/lablGL/glMat$osu $builddir/lablGL/glFunc$osu $builddir/lablGL/glClear$osu $builddir/lablGL/glPix$osu $builddir/lablGL/glTex$osu $builddir/lablGL/glDraw$osu $builddir/config$osu $builddir/lablGL/glArray$osu $builddir/main$osu $builddir/link.o -cclib "-L${LOCALBASE}/lib -lGL -lX11 -lmupdf -lz -lfreetype -ljpeg -ljbig2dec -lopenjp2 -lpthread -L$srcdir/mupdf/build/native -lcrypto $builddir/lablGL/ml_gl.o $builddir/lablGL/ml_glarray.o $builddir/lablGL/ml_raw.o"
