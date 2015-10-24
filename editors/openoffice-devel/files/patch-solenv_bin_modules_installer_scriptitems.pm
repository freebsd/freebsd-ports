--- solenv/bin/modules/installer/scriptitems.pm.orig	2014-02-27 09:52:15 UTC
+++ solenv/bin/modules/installer/scriptitems.pm
@@ -608,7 +608,7 @@
     }
 
     # Find the prereg directory entry so that we can create a new sub-directory.
-    my $parentdir_gid = "gid_Brand_Dir_Share_Prereg_Bundled";
+    my $parentdir_gid = "gid_Brand_Dir_Share_Extensions";
     my $parentdir = undef;
     foreach my $dir (@{$dirsref})
     {
@@ -645,7 +645,7 @@
             'UnixRights' => '444',
             'sourcepath' => File::Spec->catfile($ENV{'OUTDIR'}, "bin", $filename),
             'specificlanguage' => "",
-            'modules' => "gid_Module_Dictionaries",
+            'modules' => "gid_Module_Root_Brand",
             'gid' => "gid_File_Extension_".$basename
         };
         push( @filelist, $onefile);
