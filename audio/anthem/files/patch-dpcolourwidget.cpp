*** ../anthem-0.0.17.old/anthem/gadgets/DPColourWidget.cpp	Sun Jul 28 11:13:05 2002
--- anthem/gadgets/DPColourWidget.cpp	Wed Nov 12 21:47:26 2003
***************
*** 47,54 ****
  }
  
  
! DPColourWidget::DPColourWidget(TSE3::DisplayParams *dp = 0, bool useDefault,
!                                QWidget *parent = 0, const char *name = 0)
  : QComboBox(parent, name), _style(0), _preset(0)
  {
      if (useDefault)
--- 47,54 ----
  }
  
  
! DPColourWidget::DPColourWidget(TSE3::DisplayParams *dp , bool useDefault ,
!                                QWidget *parent , const char *name )
  : QComboBox(parent, name), _style(0), _preset(0)
  {
      if (useDefault)
