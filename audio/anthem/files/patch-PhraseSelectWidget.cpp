*** ../anthem-0.0.17.old/anthem/gadgets/PhraseSelectWidget.cpp	Sun Jul 28 11:13:05 2002
--- anthem/gadgets/PhraseSelectWidget.cpp	Wed Nov 12 21:47:26 2003
***************
*** 34,40 ****
  PhraseSelectWidget::PhraseSelectWidget(TSE3::PhraseList *phraseList,
                                         bool allowNone,
                                         TSE3::Phrase *selected,
!                                        QWidget *parent, const char *name = 0)
  : QComboBox(false, parent, name), phraseList(phraseList), allowNone(allowNone)
  {
      setInsertionPolicy(NoInsertion);
--- 34,40 ----
  PhraseSelectWidget::PhraseSelectWidget(TSE3::PhraseList *phraseList,
                                         bool allowNone,
                                         TSE3::Phrase *selected,
!                                        QWidget *parent, const char *name )
  : QComboBox(false, parent, name), phraseList(phraseList), allowNone(allowNone)
  {
      setInsertionPolicy(NoInsertion);
***************
*** 107,113 ****
                                                 TSE3::Phrase *selected,
                                                 TSE3::Song *song,
                                                 QWidget *parent,
!                                                const char *name = 0)
  : QWidget(parent, name), song(song)
  {
      QHBoxLayout *layout = new QHBoxLayout(this, 0, KDialogBase::spacingHint());
--- 107,113 ----
                                                 TSE3::Phrase *selected,
                                                 TSE3::Song *song,
                                                 QWidget *parent,
!                                                const char *name )
  : QWidget(parent, name), song(song)
  {
      QHBoxLayout *layout = new QHBoxLayout(this, 0, KDialogBase::spacingHint());
