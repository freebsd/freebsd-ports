*** ../anthem-0.0.17.old/anthem/tse3/kdeui/ClockWidget.cpp	Sun Jul 28 11:13:09 2002
--- anthem/tse3/kdeui/ClockWidget.cpp	Wed Nov 12 21:47:26 2003
***************
*** 61,68 ****
  };
  
  
! ClockSpinBox::ClockSpinBox(int min, int max, int step = 1,
!                            QWidget *parent = 0, const char *name = 0)
  : QSpinBox(min, max, step, parent, name), replace(false)
  {
  }
--- 61,68 ----
  };
  
  
! ClockSpinBox::ClockSpinBox(int min, int max, int step ,
!                            QWidget *parent , const char *name )
  : QSpinBox(min, max, step, parent, name), replace(false)
  {
  }
