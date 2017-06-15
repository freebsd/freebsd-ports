--- build.sh.orig	2016-11-29 15:11:31 UTC
+++ build.sh
@@ -7,7 +7,7 @@ else
     builddir="$1"
 fi
 
-ccopt="$CFLAGS -Wno-pointer-sign -O2"
+ccopt="$CFLAGS -Wno-pointer-sign -I${LOCALBASE}/include"
 mlopt='-warn-error +a -w +a -g -safe-string'
 if test -z "$native"; then
     comp=ocamlc.opt
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
@@ -45,8 +45,9 @@ $comp -c $mloptgl -o $builddir/lablGL/gl
 $comp -c -o $builddir/help$osu $builddir/help.ml
 $comp -c $mlopt -o $builddir/utils$osu $srcdir/utils.ml
 $comp -c $mlopt -I $builddir -o $builddir/parser$osu $srcdir/parser.ml
+$comp -c $mlopt -I $builddir -o $builddir/keys$osu $srcdir/keys.ml
 $comp -c $mlopt -I $builddir -o $builddir/wsi.cmi $srcdir/wsi.mli
 $comp -c $mloptgl -I $builddir -o $builddir/config$osu $srcdir/config.ml
 $comp -c $mloptgl -I $builddir -o $builddir/main$osu $srcdir/main.ml
 $comp -c $mlopt -I $builddir -o $builddir/wsi$osu $srcdir/wsi.ml
-$comp -g $lfl -I lablGL -o $builddir/llpp unix$asu str$asu $builddir/help$osu $builddir/lablGL/raw$osu $builddir/utils$osu $builddir/parser$osu $builddir/lablGL/glMisc$osu $builddir/wsi$osu $builddir/lablGL/gl$osu $builddir/lablGL/glMat$osu $builddir/lablGL/glFunc$osu $builddir/lablGL/glClear$osu $builddir/lablGL/glPix$osu $builddir/lablGL/glTex$osu $builddir/lablGL/glDraw$osu $builddir/config$osu $builddir/lablGL/glArray$osu $builddir/main$osu $builddir/link.o -cclib "-lGL -lX11 -lmupdf -lmupdfthird -lpthread -L$srcdir/mupdf/build/native -lcrypto $builddir/lablGL/ml_gl.o $builddir/lablGL/ml_glarray.o $builddir/lablGL/ml_raw.o"
+$comp $lfl -I lablGL -o $builddir/llpp unix$asu str$asu $builddir/help$osu $builddir/lablGL/raw$osu $builddir/utils$osu $builddir/parser$osu $builddir/lablGL/glMisc$osu $builddir/wsi$osu $builddir/lablGL/gl$osu $builddir/lablGL/glMat$osu $builddir/lablGL/glFunc$osu $builddir/lablGL/glClear$osu $builddir/lablGL/glPix$osu $builddir/lablGL/glTex$osu $builddir/lablGL/glDraw$osu $builddir/config$osu $builddir/lablGL/glArray$osu $builddir/main$osu $builddir/link.o -cclib "-L${LOCALBASE}/lib -lGL -lX11 -lmupdf -lmupdfthird -lharfbuzz -lz -lfreetype -ljpeg -ljbig2dec -lopenjp2 -lpthread -L$srcdir/mupdf/build/native -lcrypto $builddir/lablGL/ml_gl.o $builddir/lablGL/ml_glarray.o $builddir/lablGL/ml_raw.o"
