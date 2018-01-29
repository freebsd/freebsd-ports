--- build.sh.orig	2018-01-17 13:10:18 UTC
+++ build.sh
@@ -7,14 +7,14 @@ rm -f bin/extend
 rm -f bin/muri
 
 cd tools
-cc -O3 -c embedimage.c -o embedimage.o
-cc -O3 -c extend.c -o extend.o
-cc -O3 -c unu.c -o unu.o
-cc -O3 -c muri.c -o muri.o
-cc unu.o        -lm -o unu
-cc muri.o       -lm -o muri
-cc embedimage.o -lm -o embedimage
-cc extend.o     -lm -o extend
+$CC $CFLAGS -c embedimage.c -o embedimage.o
+$CC $CFLAGS -c extend.c -o extend.o
+$CC $CFLAGS -c unu.c -o unu.o
+$CC $CFLAGS -c muri.c -o muri.o
+$CC $LDFLAGS unu.o        -lm -o unu
+$CC $LDFLAGS muri.o       -lm -o muri
+$CC $LDFLAGS embedimage.o -lm -o embedimage
+$CC $LDFLAGS extend.o     -lm -o extend
 mv embedimage ../bin
 mv extend ../bin
 mv unu ../bin
@@ -45,16 +45,16 @@ cd interfaces
 ../bin/extend rre.forth
 ../bin/embedimage >image.c
 rm ngaImage
-cc -O3 -c rre.c -o rre.o
-cc -O3 -c repl.c -o repl.o
-cc rre.o -lm -o rre
-cc repl.o -o repl
+$CC $CFLAGS -c rre.c -o rre.o
+$CC $CFLAGS -c repl.c -o repl.o
+$CC $LDFLAGS rre.o -lm -o rre
+$CC $LDFLAGS repl.o -o repl
 mv rre ../bin
 mv repl ../bin
 rm *.o
 cd ..
 
 echo "Update Glossary"
-cat words.tsv | sort >/tmp/words
-mv /tmp/words words.tsv
+cat words.tsv | sort >words.tmp
+mv words.tmp words.tsv
 ./bin/rre glossary.forth export glossary >doc/Glossary.txt
