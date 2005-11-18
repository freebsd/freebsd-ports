*** examples/myMemReleaser/myMemReleaser.pro.orig	Sat Oct 29 16:00:35 2005
--- examples/myMemReleaser/myMemReleaser.pro	Sat Oct 29 16:00:50 2005
***************
*** 1,6 ****
--- 1,8 ----
  CONFIG *= thread
  CONFIG -= qt
  
+ INCLUDEPATH *= /usr/X11R6/include
+ 
  # needs to be added if the library uses Qt xml parser. Can be removed if not.
  macx: QMAKE_LFLAGS += -lqt
  
