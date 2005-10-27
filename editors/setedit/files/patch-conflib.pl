*** conflib.pl.orig	Wed Oct 26 21:55:24 2005
--- conflib.pl	Wed Oct 26 21:57:36 2005
***************
*** 246,252 ****
      else
       {
        if ($OSf eq 'FreeBSD')
!         { $prefix='/usr/local'; }
        else
          { $prefix='/usr'; }
       }
--- 246,252 ----
      else
       {
        if ($OSf eq 'FreeBSD')
!         { $prefix=$ENV{'PREFIX'}; }
        else
          { $prefix='/usr'; }
       }
***************
*** 567,573 ****
         $ret.=' -pipe' if $UsePipe;
         # Looks like that's common and some sysadmins doesn't configure gcc to
         # look there:
!        $conf{'EXTRA_INCLUDE_DIRS'}.=' /usr/local/include' if ($OSf eq 'FreeBSD');
        }
     }
   print "$ret\n";
--- 567,573 ----
         $ret.=' -pipe' if $UsePipe;
         # Looks like that's common and some sysadmins doesn't configure gcc to
         # look there:
!        $conf{'EXTRA_INCLUDE_DIRS'}.=' ' . $ENV{'LOCALBASE'} . '/include' if ($OSf eq 'FreeBSD');
        }
     }
   print "$ret\n";
***************
*** 596,602 ****
      return $ret;
     }
   $ret='';
!  $ret.='/usr/local/lib' if ($OSf eq 'FreeBSD');
   $conf{'LDExtraDirs'}=$ret;
   $ret;
  }
--- 596,602 ----
      return $ret;
     }
   $ret='';
!  $ret.=$ENV{'LOCALBASE'} . '/lib' if ($OSf eq 'FreeBSD');
   $conf{'LDExtraDirs'}=$ret;
   $ret;
  }
***************
*** 639,646 ****
        {
         $ret='-O2'; # -gstabs+3';
         $ret.=' -pipe' if $UsePipe;
!        $ret.=' -L/usr/local/include' if ($OSf eq 'FreeBSD');
!        $conf{'EXTRA_INCLUDE_DIRS'}.=' /usr/local/include' if ($OSf eq 'FreeBSD');
        }
     }
   print "$ret\n";
--- 639,646 ----
        {
         $ret='-O2'; # -gstabs+3';
         $ret.=' -pipe' if $UsePipe;
!        $ret.=' -L' . $ENV{'LOCALBASE'} . '/include' if ($OSf eq 'FreeBSD');
!        $conf{'EXTRA_INCLUDE_DIRS'}.=' ' . $ENV{'LOCALBASE'} . '/include' if ($OSf eq 'FreeBSD');
        }
     }
   print "$ret\n";
