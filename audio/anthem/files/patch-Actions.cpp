*** ../anthem-0.0.17.old/anthem/songwindow/Actions.cpp	Sun Jul 28 11:13:08 2002
--- anthem/songwindow/Actions.cpp	Wed Nov 12 21:47:26 2003
***************
*** 101,107 ****
  AutoRepeatAction::AutoRepeatAction(const QString& text, const QString& pix,
                                     int accel, const QObject* receiver,
                                     const char* slot,
!                                    QObject* parent, const char* name = 0)
  : KAction(text, pix, accel, receiver, slot, parent, name)
  {
  }
--- 101,107 ----
  AutoRepeatAction::AutoRepeatAction(const QString& text, const QString& pix,
                                     int accel, const QObject* receiver,
                                     const char* slot,
!                                    QObject* parent, const char* name )
  : KAction(text, pix, accel, receiver, slot, parent, name)
  {
  }
***************
*** 138,144 ****
  RepeatToggleAction::RepeatToggleAction(const QString& text, const QString& pix,
                                         int accel, const QObject* receiver,
                                         const char* slot,
!                                        QObject* parent, const char* name = 0)
  : KToggleAction(text, pix, accel, receiver, slot, parent, name)
  {
  }
--- 138,144 ----
  RepeatToggleAction::RepeatToggleAction(const QString& text, const QString& pix,
                                         int accel, const QObject* receiver,
                                         const char* slot,
!                                        QObject* parent, const char* name )
  : KToggleAction(text, pix, accel, receiver, slot, parent, name)
  {
  }
