--- regress/cmdline/blame.sh.orig	2026-10-16 10:35:44 UTC
+++ regress/cmdline/blame.sh
@@ -24,7 +24,8 @@ blame_cmp() {
 	(cd $testroot/wt && got blame "$file" | cut -d ' ' -f 2 \
 		> $testroot/${file}.blame.got)
 	git -C $testroot/repo reset --hard master > /dev/null
-	git -C $testroot/repo blame "$file" | cut -d ' ' -f 1 \
+	# git <2.56 outputs n+1 characters
+	git -C $testroot/repo blame --abbrev=8 "$file" | cut -c1-8 \
 		> $testroot/${file}.blame.git
 
 	cmp -s $testroot/${file}.blame.git $testroot/${file}.blame.got
