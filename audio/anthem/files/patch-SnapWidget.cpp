*** ../anthem-0.0.17.old/anthem/tse3/kdeui/SnapWidget.cpp	Sun Jul 28 11:08:05 2002
--- anthem/tse3/kdeui/SnapWidget.cpp	Wed Nov 12 21:47:26 2003
***************
*** 34,40 ****
  };
  
  
! SnapWidget::SnapWidget(QWidget *parent, const char *name = 0)
  : QComboBox(false, parent, name)
  {
      setInsertionPolicy(NoInsertion);
--- 34,40 ----
  };
  
  
! SnapWidget::SnapWidget(QWidget *parent, const char *name )
  : QComboBox(false, parent, name)
  {
      setInsertionPolicy(NoInsertion);
