--- conflib.pl.orig	2006-11-22 06:53:21.000000000 -0800
+++ conflib.pl	2010-06-10 01:33:44.000000000 -0700
@@ -246,7 +246,7 @@
     else
      {
       if ($OSf eq 'FreeBSD')
-        { $prefix='/usr/local'; }
+        { $prefix=$ENV{'PREFIX'}; }
       else
         { $prefix='/usr'; }
      }
@@ -575,7 +575,7 @@
        $ret.=' -pipe' if $UsePipe;
        # Looks like that's common and some sysadmins doesn't configure gcc to
        # look there:
-       $conf{'EXTRA_INCLUDE_DIRS'}.=' /usr/local/include' if ($OSf eq 'FreeBSD');
+       $conf{'EXTRA_INCLUDE_DIRS'}.=' ' . $ENV{'LOCALBASE'} . '/include' if ($OSf eq 'FreeBSD');
        # gcc 4.x enables -Wpacked this by default.
        $ver=RunRedirect("$GCC -dumpversion");
        $ret.=' -Wno-packed' if $ver>=4;
@@ -607,7 +607,7 @@
     return $ret;
    }
  $ret='';
- $ret.='/usr/local/lib' if ($OSf eq 'FreeBSD');
+ $ret.=$ENV{'LOCALBASE'} . '/lib' if ($OSf eq 'FreeBSD');
  $conf{'LDExtraDirs'}=$ret;
  $ret;
 }
@@ -650,8 +650,8 @@
       {
        $ret='-O2'; # -gstabs+3';
        $ret.=' -pipe' if $UsePipe;
-       $ret.=' -L/usr/local/include' if ($OSf eq 'FreeBSD');
-       $conf{'EXTRA_INCLUDE_DIRS'}.=' /usr/local/include' if ($OSf eq 'FreeBSD');
+       $ret.=' -L' . $ENV{'LOCALBASE'} . '/include' if ($OSf eq 'FreeBSD');
+       $conf{'EXTRA_INCLUDE_DIRS'}.=' ' . $ENV{'LOCALBASE'} . '/include' if ($OSf eq 'FreeBSD');
       }
    }
  print "$ret\n";
@@ -1444,7 +1444,7 @@
     die;
    }
  if (($OSf eq 'Darwin') || ($OSf eq 'HP-UX') || ($OSf eq 'Tru64') ||
-     ($OSf eq 'Solaris'))
+     ($OSf eq 'Solaris') || ($OSf eq 'FreeBSD'))
    {
     $conf{'GNU_AR'}='ar';
     $conf{'UseRanLib'}=1;
