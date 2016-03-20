--- tests/test.sh.orig	2015-12-27 22:40:35 UTC
+++ tests/test.sh
@@ -5,14 +5,6 @@ set -e
 exec 4>&1
 exec 1>&2
 
-cd ..
-make clean || true
-sh autogen.sh
-./configure --prefix="`pwd`/tests" --enable-shared --disable-static "$@"
-make
-make install
-cd tests
-
 rm -rf html
 rm -f *.dds
 mkdir html
@@ -143,10 +135,9 @@ html_end()
 
 timing()
 {
-	t0=`date +%s%N`
-	"$@"
-	t1=`date +%s%N`
-	deltatime_raw=`echo "$t1 - $t0" | bc`
+	/usr/bin/time -p -o timing.log "$@"
+	t=`cat timing.log | head -n 1 | cut -f 2 -d ' '`
+	deltatime_raw=`echo "$t * 1000000000" | bc`
 	deltatime=`echo "scale=3; $deltatime_raw / 1000000000" | bc -l`
 	deltatime=" ($deltatime seconds)"
 }
@@ -197,7 +188,7 @@ xon textures/facility114x/misc/lift02.tg
 # sunset: GPLv2+
 xon env/distant_sunset/distant_sunset_rt.jpg sunset.tga
 
-export LD_LIBRARY_PATH="$PWD/lib"
+export LD_LIBRARY_PATH="$PWD/../.libs"
 for i in dxtfail floor_tread01_norm fract001 base_concrete1a disabled lift02 sunset noise noise_solid supernova; do
 	html_rowstart "$i"
 
@@ -228,21 +219,21 @@ for i in dxtfail floor_tread01_norm frac
 	if $use_nvcompress; then
 		timing nvcompress $nvopts "$i".tga "$i"-nvcompress.dds
 		html "$i"-nvcompress.dds
-		timing bin/s2tc_from_s3tc -i "$i"-nvcompress.dds -o "$i"-nvcompress-s2tc.dds
+		timing ../s2tc_from_s3tc -i "$i"-nvcompress.dds -o "$i"-nvcompress-s2tc.dds
 		html "$i"-nvcompress-s2tc.dds
 	fi
 
 	S2TC_DITHER_MODE=FLOYDSTEINBERG S2TC_COLORDIST_MODE=$goodmetric S2TC_RANDOM_COLORS=32 S2TC_REFINE_COLORS=LOOP \
-	t "$i".tga "$i"-rand32-mrgb-l.dds bin/s2tc_compress -t $fourcc
+	t "$i".tga "$i"-rand32-mrgb-l.dds ../s2tc_compress -t $fourcc
 	if $use_libtxc_dxtn; then
 		t "$i".tga "$i"-libtxc_dxtn.dds   bin/s2tc_compress -t $fourcc -l /usr/lib/libtxc_dxtn.so
 		timing bin/s2tc_from_s3tc -i "$i"-libtxc_dxtn.dds -o "$i"-libtxc_dxtn-s2tc.dds
 		html "$i"-libtxc_dxtn-s2tc.dds
 	fi
 	S2TC_DITHER_MODE=SIMPLE         S2TC_COLORDIST_MODE=WAVG        S2TC_RANDOM_COLORS=-1 S2TC_REFINE_COLORS=ALWAYS \
-	t "$i".tga "$i"-faster-wavg-r.dds bin/s2tc_compress -t $fourcc
+	t "$i".tga "$i"-faster-wavg-r.dds ../s2tc_compress -t $fourcc
 	S2TC_DITHER_MODE=SIMPLE         S2TC_COLORDIST_MODE=WAVG        S2TC_RANDOM_COLORS=-1 S2TC_REFINE_COLORS=LOOP \
-	t "$i".tga "$i"-faster-wavg-l.dds bin/s2tc_compress -t $fourcc
+	t "$i".tga "$i"-faster-wavg-l.dds ../s2tc_compress -t $fourcc
 
 	html_rowend
 done
