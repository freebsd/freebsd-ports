*** ../anthem-0.0.17.old/anthem/gadgets/RubberSelectionBox.cpp	Sun Jul 28 11:13:06 2002
--- anthem/gadgets/RubberSelectionBox.cpp	Wed Nov 12 21:47:26 2003
***************
*** 41,47 ****
  
  
  void RubberSelectionBox::startAnchoredDrag(int x, int y, int width, int height,
!                                            int private_word = 0,
                                             bool autoScroll,
                                             bool constrain,
                                             int minx, int miny,
--- 41,47 ----
  
  
  void RubberSelectionBox::startAnchoredDrag(int x, int y, int width, int height,
!                                            int private_word ,
                                             bool autoScroll,
                                             bool constrain,
                                             int minx, int miny,
***************
*** 75,81 ****
  
  
  void RubberSelectionBox::startDragBox(int x, int y,
!                                       int private_word = 0,
                                        int boxx, int boxy,
                                        int boxwidth, int boxheight,
                                        bool autoScroll,
--- 75,81 ----
  
  
  void RubberSelectionBox::startDragBox(int x, int y,
!                                       int private_word ,
                                        int boxx, int boxy,
                                        int boxwidth, int boxheight,
                                        bool autoScroll,
