--- config.pl.orig	2004-10-12 12:00:54.000000000 -0700
+++ config.pl	2010-06-10 01:14:22.000000000 -0700
@@ -169,7 +169,7 @@
   }
 elsif ($OS eq 'UNIX')
   {
-   $MakeDefsRHIDE[0]='RHIDE_STDINC=/usr/include /usr/local/include /usr/include/g++ /usr/local/include/g++ /usr/lib/gcc-lib /usr/local/lib/gcc-lib';
+   $MakeDefsRHIDE[0]='RHIDE_STDINC=/usr/include ' . $ENV{'LOCALBASE'} . '/include /usr/include/g++ ' . $ENV{'LOCALBASE'} . '/include/g++ /usr/lib/gcc-lib ' . $ENV{'LOCALBASE'} . '/lib/gcc-lib';
    if (@conf{'static'} eq 'yes')
       { $libs=TVConfigOption('slibs'); }
    else
@@ -456,9 +456,9 @@
     elsif ($i eq '--debug')
       {
        $conf{'XCFLAGS'}=
-       $conf{'XCXXFLAGS'}='-O3 -fomit-frame-pointer -ffast-math -gstabs+3';
+       $conf{'XCXXFLAGS'}='-O3 -fomit-frame-pointer -ffast-math';
        $conf{'CFLAGS'}=
-       $conf{'CXXFLAGS'}='-O2 -Wall -Werror -gstabs+3';
+       $conf{'CXXFLAGS'}='-O2 -Wall -Werror';
       }
     elsif ($i eq '--with-mixer')
       {
@@ -783,8 +783,8 @@
    }
  elsif ($OS eq 'UNIX')
    {
-    @dirsI=("$parent/tvision/include",'/usr/include/rhtvision','/usr/local/include/rhtvision');
-    @dirsL=("$parent/tvision/makes",'/usr/lib','/usr/local/lib');
+    @dirsI=("$parent/tvision/include",'/usr/include/rhtvision',$ENV{'LOCALBASE'} . '/include/rhtvision');
+    @dirsL=("$parent/tvision/makes",'/usr/lib',$ENV{'LOCALBASE'} . '/lib');
    }
  elsif ($OS eq 'Win32')
    {
@@ -1856,7 +1856,7 @@
  return 0;
 }
 ';
- $conf{'X11LibPath'}='/usr/X11R6/lib' unless $conf{'X11LibPath'};
+ $conf{'X11LibPath'}=$ENV{'LOCALBASE'} . '/lib' unless $conf{'X11LibPath'};
  $conf{'X11Lib'}='X11 Xmu' unless $conf{'X11Lib'};
  $libs=$conf{'X11Lib'};
  $libs=~s/(\S+)/-l$1/g;
@@ -1873,7 +1873,7 @@
    {
     if (!$conf{'X11IncludePath'})
       {
-       $conf{'X11IncludePath'}='/usr/X11R6/include';
+       $conf{'X11IncludePath'}=$ENV{'LOCALBASE'} . '/include';
        $o.="-I$conf{'X11IncludePath'} -L$conf{'X11LibPath'} $libs";
        if ($test=~/OK, (\d+)\.(\d+)/)
          {
