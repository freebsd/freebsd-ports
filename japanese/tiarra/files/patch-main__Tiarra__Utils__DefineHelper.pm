Index: main/Tiarra/Utils/DefineHelper.pm
diff -u main/Tiarra/Utils/DefineHelper.pm.orig main/Tiarra/Utils/DefineHelper.pm
--- main/Tiarra/Utils/DefineHelper.pm.orig	2010-02-12 03:34:30.000000000 +0900
+++ main/Tiarra/Utils/DefineHelper.pm	2015-09-02 01:20:26.908910808 +0900
@@ -345,9 +345,10 @@
 	} else {
 	    @funcnames = $_;
 	}
+	my $j = $i;
 	$pkg->define_function(
 	    $pkg->get_package,
-	    sub () { $i; },
+	    sub () { $j; },
 	    @funcnames);
 	++$i;
     }
