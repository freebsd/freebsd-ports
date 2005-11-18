*** examples/examples.pro.orig	Sat Oct 29 15:57:38 2005
--- examples/examples.pro	Sat Oct 29 15:57:44 2005
***************
*** 1,4 ****
--- 1,5 ----
  TEMPLATE = subdirs
+ INCLUDEPATH *= /usr/X11R6/include
  
  SUBDIRS = \
          X3DViewer \
***************
*** 16,20 ****
          simpleNodeCounter \
          meshCreation \
          simplifiedMeshViewer \
!         redefineNodeTester \
!         mySimplifiedMeshViewer
--- 17,21 ----
          simpleNodeCounter \
          meshCreation \
          simplifiedMeshViewer \
!         redefineNodeTester
! 
