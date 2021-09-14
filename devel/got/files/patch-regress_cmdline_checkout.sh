--- regress/cmdline/checkout.sh.orig	2021-09-14 20:09:50 UTC
+++ regress/cmdline/checkout.sh
@@ -821,7 +821,7 @@ test_checkout_quiet() {
 
 	echo -n "Checked out refs/heads/master: " >> $testroot/stdout.expected
 	git_show_head $testroot/repo >> $testroot/stdout.expected
-	echo "\nNow shut up and hack" >> $testroot/stdout.expected
+	printf "\nNow shut up and hack\n" >> $testroot/stdout.expected
 
 	got checkout -q $testroot/repo $testroot/wt > $testroot/stdout
 	ret="$?"
