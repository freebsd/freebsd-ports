--- lib/Config/Model.pm.orig	2016-06-29 17:34:35 UTC
+++ lib/Config/Model.pm
@@ -718,10 +718,10 @@ sub translate_compute_info {
         map { $replace_h = delete $var{$_} if ref( $var{$_} ) } keys %var;
 
         # cleanup user formula
-        $user_formula =~ s/\$(\w+){/\$replace{/g;
+        $user_formula =~ s/\$(\w+)\{/\$replace{/g;
 
         # cleanup variable
-        map { s/\$(\w+){/\$replace{/g } values %var;
+        map { s/\$(\w+)\{/\$replace{/g } values %var;
 
         # change the hash *in* the info structure
         $info->{$new_name} = {
