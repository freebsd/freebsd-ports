*** ../anthem-0.0.17.old/anthem/gadgets/VoiceWidget.cpp	Sun Jul 28 11:13:06 2002
--- anthem/gadgets/VoiceWidget.cpp	Wed Nov 12 21:47:26 2003
***************
*** 198,204 ****
   * VoiceByNumberPopup class
   *****************************************************************************/
  
! VoiceByNumberPopup::VoiceByNumberPopup(QWidget *parent, const char *name = 0)
  : QPopupMenu(parent, name)
  {
      QWidget *item = new QWidget(this);
--- 198,204 ----
   * VoiceByNumberPopup class
   *****************************************************************************/
  
! VoiceByNumberPopup::VoiceByNumberPopup(QWidget *parent, const char *name )
  : QPopupMenu(parent, name)
  {
      QWidget *item = new QWidget(this);
***************
*** 313,319 ****
      };
  }
  
! VoiceByNamePopup::VoiceByNamePopup(QWidget *parent, const char *name = 0)
  : QPopupMenu(parent, name), channel(0), port(0)
  {
      QWidget *item = new QWidget(this);
--- 313,319 ----
      };
  }
  
! VoiceByNamePopup::VoiceByNamePopup(QWidget *parent, const char *name )
  : QPopupMenu(parent, name), channel(0), port(0)
  {
      QWidget *item = new QWidget(this);
