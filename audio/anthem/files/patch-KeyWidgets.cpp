*** ../anthem-0.0.17.old/anthem/gadgets/KeyWidgets.cpp	Sun Jul 28 11:12:53 2002
--- anthem/gadgets/KeyWidgets.cpp	Wed Nov 12 21:47:26 2003
***************
*** 140,146 ****
  };
  
  
! KeySpinBox::KeySpinBox(QWidget *parent = 0, const char *name = 0)
  : QSpinBox(0, 127, 1, parent, name)
  {
  }
--- 140,146 ----
  };
  
  
! KeySpinBox::KeySpinBox(QWidget *parent , const char *name )
  : QSpinBox(0, 127, 1, parent, name)
  {
  }
