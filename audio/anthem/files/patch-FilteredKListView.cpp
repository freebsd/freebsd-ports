*** ../anthem-0.0.17.old/anthem/gadgets/FilteredKListView.cpp	Sun Jul 28 11:13:05 2002
--- anthem/gadgets/FilteredKListView.cpp	Wed Nov 12 21:47:26 2003
***************
*** 17,23 ****
  
  #include <algorithm>
  
! FilteredKListView::FilteredKListView(QWidget *parent, const char *name = 0)
  : KListView(parent, name), lastClickIndex(-1)
  {
      setMargins(0,0,0,horizontalScrollBar()->sizeHint().height());
--- 17,23 ----
  
  #include <algorithm>
  
! FilteredKListView::FilteredKListView(QWidget *parent, const char *name )
  : KListView(parent, name), lastClickIndex(-1)
  {
      setMargins(0,0,0,horizontalScrollBar()->sizeHint().height());
