*** ../anthem-0.0.17.old/anthem/gadgets/PartInsertActionWidget.cpp	Sun Jul 28 11:09:48 2002
--- anthem/gadgets/PartInsertActionWidget.cpp	Wed Nov 12 21:47:26 2003
***************
*** 30,36 ****
  
  
  PartInsertActionWidget::PartInsertActionWidget(QWidget *parent,
!                                                const char *name = 0)
  : QComboBox(false, parent, name)
  {
      setInsertionPolicy(NoInsertion);
--- 30,36 ----
  
  
  PartInsertActionWidget::PartInsertActionWidget(QWidget *parent,
!                                                const char *name )
  : QComboBox(false, parent, name)
  {
      setInsertionPolicy(NoInsertion);
