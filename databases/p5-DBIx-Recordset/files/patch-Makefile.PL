*** Makefile.PL.orig	Sun Apr 29 19:51:53 2001
--- Makefile.PL	Sun Apr 29 19:52:04 2001
***************
*** 8,13 ****
--- 8,14 ----
  
  use ExtUtils::MakeMaker;
  
+ =item
  # Ignore the following DBD Drivers
  
  %ignore = ('ExampleP' => 1,
***************
*** 183,189 ****
  
  close FH ;
      } 
! 
  
  WriteMakefile
      (
--- 184,190 ----
  
  close FH ;
      } 
! =cut
  
  WriteMakefile
      (
