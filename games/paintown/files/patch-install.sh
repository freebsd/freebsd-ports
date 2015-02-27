--- install.sh.orig	2011-10-16 21:33:08.000000000 +0400
+++ install.sh	2015-01-16 21:12:03.739066101 +0300
@@ -18,7 +18,7 @@
 ## Default bin directory is /usr/games
 
 data(){
-	dir=$1
+	dir=$DESTDIR/$1
 
 	if [ ! -f paintown ]; then
 		echo "You must compile paintown first. Read the README for instructions or just type make"
@@ -35,7 +35,7 @@
 
 bin(){
 	data_dir=$1
-	bin_dir=$2
+	bin_dir=$DESTDIR/$2
 
     mkdir -p $bin_dir
 	echo "$data_dir/paintown-bin -d $data_dir/data $*" >> $bin_dir/paintown
