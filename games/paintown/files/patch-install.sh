--- install.sh.orig	2010-04-14 20:48:09.000000000 +0200
+++ install.sh	2010-04-14 20:48:08.000000000 +0200
@@ -28,8 +28,8 @@
 	echo "Copying data to $dir"
 	mkdir -p $dir
 
-	find data -type d ! -regex '.*\.svn.*' -print0 | xargs -i -0 mkdir -p "$dir/{}"
-	find data -type f ! -regex '.*\.svn.*' -print0 | xargs -i -0 cp "{}" "$dir/{}"
+	find data -type d ! -regex '.*\.svn.*' -print0 | xargs -0 -I "{}" mkdir -p "$dir/{}"
+	find data -type f ! -regex '.*\.svn.*' -print0 | xargs -0 -I "{}" cp "{}" "$dir/{}"
 	cp paintown $dir/paintown-bin
 }
 
