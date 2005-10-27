*** config.pl.orig	Tue Oct 12 22:00:54 2004
--- config.pl	Thu Oct 27 12:06:23 2005
***************
*** 169,175 ****
    }
  elsif ($OS eq 'UNIX')
    {
!    $MakeDefsRHIDE[0]='RHIDE_STDINC=/usr/include /usr/local/include /usr/include/g++ /usr/local/include/g++ /usr/lib/gcc-lib /usr/local/lib/gcc-lib';
     if (@conf{'static'} eq 'yes')
        { $libs=TVConfigOption('slibs'); }
     else
--- 169,175 ----
    }
  elsif ($OS eq 'UNIX')
    {
!    $MakeDefsRHIDE[0]='RHIDE_STDINC=/usr/include ' . $ENV{'LOCALBASE'} . '/include /usr/include/g++ ' . $ENV{'LOCALBASE'} . '/include/g++ /usr/lib/gcc-lib ' . $ENV{'LOCALBASE'} . '/lib/gcc-lib';
     if (@conf{'static'} eq 'yes')
        { $libs=TVConfigOption('slibs'); }
     else
***************
*** 456,464 ****
      elsif ($i eq '--debug')
        {
         $conf{'XCFLAGS'}=
!        $conf{'XCXXFLAGS'}='-O3 -fomit-frame-pointer -ffast-math -gstabs+3';
         $conf{'CFLAGS'}=
!        $conf{'CXXFLAGS'}='-O2 -Wall -Werror -gstabs+3';
        }
      elsif ($i eq '--with-mixer')
        {
--- 456,464 ----
      elsif ($i eq '--debug')
        {
         $conf{'XCFLAGS'}=
!        $conf{'XCXXFLAGS'}='-O3 -fomit-frame-pointer -ffast-math';
         $conf{'CFLAGS'}=
!        $conf{'CXXFLAGS'}='-O2 -Wall -Werror';
        }
      elsif ($i eq '--with-mixer')
        {
***************
*** 783,790 ****
     }
   elsif ($OS eq 'UNIX')
     {
!     @dirsI=("$parent/tvision/include",'/usr/include/rhtvision','/usr/local/include/rhtvision');
!     @dirsL=("$parent/tvision/makes",'/usr/lib','/usr/local/lib');
     }
   elsif ($OS eq 'Win32')
     {
--- 783,790 ----
     }
   elsif ($OS eq 'UNIX')
     {
!     @dirsI=("$parent/tvision/include",'/usr/include/rhtvision',$ENV{'LOCALBASE'} . '/include/rhtvision');
!     @dirsL=("$parent/tvision/makes",'/usr/lib',$ENV{'LOCALBASE'} . '/lib');
     }
   elsif ($OS eq 'Win32')
     {
***************
*** 1856,1862 ****
   return 0;
  }
  ';
!  $conf{'X11LibPath'}='/usr/X11R6/lib' unless $conf{'X11LibPath'};
   $conf{'X11Lib'}='X11 Xmu' unless $conf{'X11Lib'};
   $libs=$conf{'X11Lib'};
   $libs=~s/(\S+)/-l$1/g;
--- 1856,1862 ----
   return 0;
  }
  ';
!  $conf{'X11LibPath'}=$ENV{'X11BASE'} . '/lib' unless $conf{'X11LibPath'};
   $conf{'X11Lib'}='X11 Xmu' unless $conf{'X11Lib'};
   $libs=$conf{'X11Lib'};
   $libs=~s/(\S+)/-l$1/g;
***************
*** 1873,1879 ****
     {
      if (!$conf{'X11IncludePath'})
        {
!        $conf{'X11IncludePath'}='/usr/X11R6/include';
         $o.="-I$conf{'X11IncludePath'} -L$conf{'X11LibPath'} $libs";
         if ($test=~/OK, (\d+)\.(\d+)/)
           {
--- 1873,1879 ----
     {
      if (!$conf{'X11IncludePath'})
        {
!        $conf{'X11IncludePath'}=$ENV{'X11BASE'} . '/include';
         $o.="-I$conf{'X11IncludePath'} -L$conf{'X11LibPath'} $libs";
         if ($test=~/OK, (\d+)\.(\d+)/)
           {
