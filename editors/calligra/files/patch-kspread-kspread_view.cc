--- ./kspread/kspread_view.cc.orig	Sat Aug 31 07:13:44 2002
+++ ./kspread/kspread_view.cc	Sun Nov 17 06:32:41 2002
@@ -1426,7 +1426,7 @@
     if(m_pDoc->getKSpellConfig())
     {
         m_pDoc->getKSpellConfig()->setIgnoreList(m_pDoc->spellListIgnoreAll());
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
         m_pDoc->getKSpellConfig()->setReplaceAllList(m_spell.replaceAll);
 #endif
 
@@ -1457,7 +1457,7 @@
   QObject::connect( m_spell.kspell, SIGNAL( ignoreall (const QString & ) ),
                     this, SLOT( spellCheckerIgnoreAll( const QString & ) ) );
 
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
   QObject::connect( m_spell.kspell, SIGNAL( replaceall( const QString &  ,  const QString & )), this, SLOT( spellCheckerReplaceAll( const QString &  ,  const QString & )));
 #endif
 
@@ -1567,7 +1567,7 @@
   m_spell.firstSpellTable   = 0L;
   m_spell.currentSpellTable = 0L;
   m_spell.currentCell       = 0L;
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
   m_spell.replaceAll.clear();
 #endif
 
@@ -1713,7 +1713,7 @@
             }
         }
     }
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
     m_spell.replaceAll.clear();
 #endif
 
@@ -1733,7 +1733,7 @@
   m_spell.kspell->cleanUp();
   delete m_spell.kspell;
   m_spell.kspell = 0L;
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
   m_spell.replaceAll.clear();
 #endif
 
