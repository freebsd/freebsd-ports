--- lib/Net/FTP/Common.pm.orig	Mon Jun  2 07:28:01 2003
+++ lib/Net/FTP/Common.pm	Mon Jun  2 07:28:04 2003
@@ -157,7 +157,8 @@
     foreach (@{$dir})
         {
 	    # $_ =~ m#([a-z-]*)\s*([0-9]*)\s*([0-9a-zA-Z]*)\s*([0-9a-zA-Z]*)\s*([0-9]*)\s*([A-Za-z]*)\s*([0-9]*)\s*([0-9A-Za-z:]*)\s*([A-Za-z0-9.-]*)#;
-	    $_ = m#([a-z-]*)\s*([0-9]*)\s*([0-9a-zA-Z]*)\s*([0-9a-zA-Z]*)\s*([0-9]*)\s*([A-Za-z]*)\s*([0-9]*)\s*([0-9A-Za-z:]*)\s*([\w*\W*\s*\S*]*)#;
+	    # $_ = m#([a-z-]*)\s*([0-9]*)\s*([0-9a-zA-Z]*)\s*([0-9a-zA-Z]*)\s*([0-9]*)\s*([A-Za-z]*)\s*([0-9]*)\s*([0-9A-Za-z:]*)\s*([\w*\W*\s*\S*]*)#;
+	    $_ =~ m#([a-z-]*)\s*([0-9]*)\s*([0-9a-zA-Z-]*)\s*([0-9a-zA-Z-]*)\s*([0-9]*)\s*([A-Za-z]*)\s*([0-9]*)\s*([0-9A-Za-z:]*)\s*(\S+)#;
 
         my $perm = $1;
         my $inode = $2;
@@ -170,7 +171,7 @@
         my $name = $9;
         my $linkTarget;
 
-        if ( $' =~ m#\s*->\s*([A-Za-z0-9.-/]*)# )       # it's a symlink
+        if ( $' =~ m#\s*->\s*([A-Za-z0-9.\-/]*)# )       # it's a symlink
                 { $linkTarget = $1; }
 
         $HoH{$name}{perm} = $perm;
