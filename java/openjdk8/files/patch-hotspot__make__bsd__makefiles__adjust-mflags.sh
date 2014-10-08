--- hotspot/make/bsd/makefiles/adjust-mflags.sh.orig	2014-03-04 02:52:06 UTC
+++ hotspot/make/bsd/makefiles/adjust-mflags.sh
@@ -64,7 +64,7 @@
 	echo "$MFLAGS" \
 	| sed '
 		s/^-/ -/
-		s/ -\([^ 	][^ 	]*\)j/ -\1 -j/
+		s/ -\([^ 	I][^ 	I]*\)j/ -\1 -j/
 		s/ -j[0-9][0-9]*/ -j/
 		s/ -j\([^ 	]\)/ -j -\1/
 		s/ -j/ -j'${HOTSPOT_BUILD_JOBS:-${default_build_jobs}}'/
