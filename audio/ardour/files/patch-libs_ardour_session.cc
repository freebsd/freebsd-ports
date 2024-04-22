--- libs/ardour/session.cc.orig	2024-02-21 00:37:39 UTC
+++ libs/ardour/session.cc
@@ -136,7 +136,10 @@
 #include "ardour/utils.h"
 #include "ardour/vca_manager.h"
 #include "ardour/vca.h"
+
+#ifdef VST3_SUPPORT
 #include "ardour/vst3_plugin.h"
+#endif // VST3_SUPPORT
 
 #include "midi++/port.h"
 #include "midi++/mmc.h"
@@ -881,10 +884,12 @@ Session::destroy ()
 
 	_transport_fsm->stop ();
 
+#ifdef VST3_SUPPORT
 	/* close VST3 Modules */
 	for (auto const& nfo : PluginManager::instance().vst3_plugin_info()) {
 		std::dynamic_pointer_cast<VST3PluginInfo> (nfo)->m.reset ();
 	}
+#endif // VST3_SUPPORT
 
 	DEBUG_TRACE (DEBUG::Destruction, "Session::destroy() done\n");
 
