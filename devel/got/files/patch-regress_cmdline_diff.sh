--- regress/cmdline/diff.sh.orig	2023-01-16 08:47:29 UTC
+++ regress/cmdline/diff.sh
@@ -1762,10 +1762,8 @@ EOF
 		return 1
 	fi
 
-	typeset -L10 short_alpha_id
-	typeset -L10 short_alpha_new_id
-	short_alpha_id=$alpha_blobid
-	short_alpha_new_id=$alpha_new_blobid
+	short_alpha_id=$(printf '%-10.10s' $alpha_blobid)
+	short_alpha_new_id=$(printf '%-10.10s' $alpha_new_blobid)
 	cat <<EOF >$testroot/stdout.expected
 diffstat $alpha_blobid $alpha_new_blobid
  M  $short_alpha_id -> $short_alpha_new_id  |  1+  1-
