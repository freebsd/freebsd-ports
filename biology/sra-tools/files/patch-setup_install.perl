--- setup/install.perl.orig	2021-03-15 18:25:25 UTC
+++ setup/install.perl
@@ -1283,8 +1283,8 @@ sub prepare {
             '   $_{INST_JARDIR  } = "$_{PREFIX}/jar"; ' .
             '   $_{INST_SHAREDIR} = "$_{PREFIX}/share"; ' .
             '   $_{INCDIR       } = "$Bin/../include"; ' .
-            '   $_{LIBDIR64     } = "$Bin/../lib64"; ' .
-            '   $_{LIBDIR32     } = "$Bin/../lib32"; ';
+            '   $_{LIBDIR64     } = "$Bin/../lib"; ' .
+            '   $_{LIBDIR32     } = "$Bin/../lib"; ';
         if ($HAVE{TWO_LIBS}) {
             $code .=
                '$_{INST_NGSLIBDIR} = "' . "$root/usr/local/ngs/ngs-sdk/lib\";"
