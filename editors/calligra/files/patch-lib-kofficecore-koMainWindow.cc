--- ./lib/kofficecore/koMainWindow.cc.orig	Sat Aug 31 07:13:56 2002
+++ ./lib/kofficecore/koMainWindow.cc	Sun Nov 17 06:33:37 2002
@@ -179,7 +179,7 @@
     d->m_manager->setSelectionPolicy( KParts::PartManager::TriState );
     d->m_manager->setAllowNestedParts( true );
     d->m_manager->setIgnoreScrollBars( true );
-#if KDE_VERSION > 305
+#if KDE_VERSION > 306
     d->m_manager->setActivationButtonMask( Qt::LeftButton | Qt::MidButton );
 #endif
 
@@ -1115,7 +1115,7 @@
     QApplication::sendEvent( d->m_activeView, &ev );
 
     // As of KDE-3.1, the plugins are child XMLGUI objects of the part
-#if KDE_VERSION < 305
+#if KDE_VERSION < 306
     QPtrList<KParts::Plugin> plugins = KParts::Plugin::pluginObjects( d->m_activeView );
     KParts::Plugin *plugin = plugins.last();
     while ( plugin )
@@ -1133,7 +1133,7 @@
 
   if ( !d->bMainWindowGUIBuilt )
   {
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
     // Load mainwindow plugins
     KParts::Plugin::loadPlugins( this, this, instance(), true );
 #endif
@@ -1149,7 +1149,7 @@
     factory->addClient( d->m_activeView );
 
     // As of KDE-3.1, the plugins are child XMLGUI objects of the part
-#if KDE_VERSION < 305
+#if KDE_VERSION < 306
     QPtrList<KParts::Plugin> plugins = KParts::Plugin::pluginObjects( d->m_activeView );
     QPtrListIterator<KParts::Plugin> pIt( plugins );
     for (; pIt.current(); ++pIt )
