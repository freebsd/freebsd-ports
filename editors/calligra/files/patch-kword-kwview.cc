--- ./kword/kwview.cc.orig	Sat Aug 31 07:13:52 2002
+++ ./kword/kwview.cc	Sun Nov 17 06:33:20 2002
@@ -1043,7 +1043,7 @@
     // Necessary for the actions that are not plugged anywhere
     // Deprecated with KDE-3.1.
     // Note entirely sure it's necessary for 3.0, please test and report.
-#if KDE_VERSION < 305
+#if KDE_VERSION < 306
     KAccel * accel = new KAccel( this );
     actNbsp->plugAccel( accel );
     actSoftHyphen->plugAccel( accel );
@@ -1928,7 +1928,7 @@
     // to individual actions
     QStringList lstWithAccels;
     // Generate unique accelerators for the menu items
-#if KDE_VERSION >= 305  // but only if the '&' will be removed from the combobox
+#if KDE_VERSION >= 306  // but only if the '&' will be removed from the combobox
     KAccelGen::generate( lst, lstWithAccels );
 #else
     lstWithAccels = lst;
@@ -1998,7 +1998,7 @@
     // to individual actions
     QStringList lstWithAccels;
     // Generate unique accelerators for the menu items
-#if KDE_VERSION >= 305  // but only if the '&' will be removed from the combobox
+#if KDE_VERSION >= 306  // but only if the '&' will be removed from the combobox
     KAccelGen::generate( lst, lstWithAccels );
 #else
     lstWithAccels = lst;
@@ -2073,7 +2073,7 @@
     // to individual actions
     QStringList lstWithAccels;
     // Generate unique accelerators for the menu items
-#if KDE_VERSION >= 305  // but only if the '&' will be removed from the combobox
+#if KDE_VERSION >= 306  // but only if the '&' will be removed from the combobox
     KAccelGen::generate( lst, lstWithAccels );
 #else
     lstWithAccels = lst;
@@ -4979,7 +4979,7 @@
     if(m_doc->getKSpellConfig())
     {
         m_doc->getKSpellConfig()->setIgnoreList(m_doc->spellListIgnoreAll());
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
         m_doc->getKSpellConfig()->setReplaceAllList(m_spell.replaceAll);
 #endif
     }
@@ -5000,7 +5000,7 @@
     QObject::connect( m_spell.kspell, SIGNAL( ignoreall (const QString & ) ),
                       this, SLOT( spellCheckerIgnoreAll( const QString & ) ) );
 
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
     QObject::connect( m_spell.kspell, SIGNAL( replaceall( const QString &  ,  const QString & )), this, SLOT( spellCheckerReplaceAll( const QString &  ,  const QString & )));
 #endif
 
