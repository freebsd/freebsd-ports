*** examples/meshTransformComputer/meshTransformComputer.pro.orig	Sat Oct 29 16:06:12 2005
--- examples/meshTransformComputer/meshTransformComputer.pro	Sat Oct 29 16:06:26 2005
***************
*** 1,6 ****
--- 1,8 ----
  CONFIG *= thread
  CONFIG -= qt
  
+ INCLUDEPATH *= /usr/X11R6/include
+ 
  # needs to be added if the library uses Qt xml parser. Can be removed if not.
  macx: QMAKE_LFLAGS += -lqt
  
