--- ktagebuch/plugins/mood/moodplugin.cpp.orig	Sun Aug 15 19:40:45 2004
+++ ktagebuch/plugins/mood/moodplugin.cpp	Sun Aug 15 19:41:02 2004
@@ -12,7 +12,7 @@
 #include "moodpluginui.h"
 #include "moodprefs.h"
 
-K_EXPORT_COMPONENT_FACTORY( ktagebuch_mood, KGenericFactory<MoodPlugin> );
+K_EXPORT_COMPONENT_FACTORY( ktagebuch_mood, KGenericFactory<MoodPlugin> )
 
 MoodPlugin::MoodPlugin( QObject *parent, const char *name,
 			      const QStringList &/*args*/ )
