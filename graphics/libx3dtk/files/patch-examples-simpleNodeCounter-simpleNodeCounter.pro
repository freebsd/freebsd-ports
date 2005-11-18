*** examples/simpleNodeCounter/simpleNodeCounter.pro.orig	Sat Oct 29 16:11:09 2005
--- examples/simpleNodeCounter/simpleNodeCounter.pro	Sat Oct 29 16:11:20 2005
***************
*** 1,6 ****
--- 1,8 ----
  CONFIG *= thread
  CONFIG -= qt
  
+ INCLUDEPATH *= /usr/X11R6/include
+ 
  # needs to be added if the library uses Qt xml parser. Can be removed if not.
  macx: QMAKE_LFLAGS += -lqt
  
