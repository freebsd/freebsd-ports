--- ./kpresenter/kpresenter_view.cc.orig	Sat Aug 31 07:13:36 2002
+++ ./kpresenter/kpresenter_view.cc	Sun Nov 17 06:31:18 2002
@@ -3224,7 +3224,7 @@
                                            actionCollection(), "format_style" );
     connect( actionFormatStyle, SIGNAL( activated( int ) ),
              this, SLOT( textStyleSelected( int ) ) );
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
     actionFormatStyle->setRemoveAmpersandsInCombo( true );
 #endif
     updateStyleList();
@@ -3972,7 +3972,7 @@
 {
     QColor c = kPresenterDoc()->presPen().color();
     if ( KColorDialog::getColor( c
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
                                  , Qt::red
 #endif
              ) ) {
@@ -5116,7 +5116,7 @@
 {
     if (m_spell.kspell) return; // Already in progress
     m_spell.macroCmdSpellCheck=0L;
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
     m_spell.replaceAll.clear();
 #endif
 
@@ -5173,7 +5173,7 @@
     if(m_pKPresenterDoc->getKSpellConfig())
     {
         m_pKPresenterDoc->getKSpellConfig()->setIgnoreList(m_pKPresenterDoc->spellListIgnoreAll());
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
         m_pKPresenterDoc->getKSpellConfig()->setReplaceAllList(m_spell.replaceAll);
 #endif
 
@@ -5194,7 +5194,7 @@
                       this, SLOT( spellCheckerDone( const QString & ) ) );
     QObject::connect( m_spell.kspell, SIGNAL( ignoreall (const QString & ) ),
                       this, SLOT( spellCheckerIgnoreAll( const QString & ) ) );
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
     QObject::connect( m_spell.kspell, SIGNAL( replaceall( const QString &, const QString & )), this, SLOT( spellCheckerReplaceAll( const QString &, const QString & )));
 #endif
 
@@ -5323,7 +5323,7 @@
     {
         m_pKPresenterDoc->setReadWrite(true);
         m_spell.textObject.clear();
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
         m_spell.replaceAll.clear();
 #endif
 
@@ -5362,7 +5362,7 @@
     m_spell.macroCmdSpellCheck=0L;
 
     m_pKPresenterDoc->setReadWrite(true);
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
     m_spell.replaceAll.clear();
 #endif
 
@@ -6273,7 +6273,7 @@
     // to individual actions
     QStringList lstWithAccels;
     // Generate unique accelerators for the menu items
-#if KDE_VERSION >= 305  // but only if the '&' will be removed from the combobox
+#if KDE_VERSION >= 306  // but only if the '&' will be removed from the combobox
     KAccelGen::generate( lst, lstWithAccels );
 #else
     lstWithAccels = lst;
