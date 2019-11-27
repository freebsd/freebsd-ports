https://github.com/ktechlab/ktechlab/issues/57

--- src/electronics/gpsimprocessor.cpp.orig	2019-11-27 15:23:04 UTC
+++ src/electronics/gpsimprocessor.cpp
@@ -755,7 +755,7 @@ RegisterSet::RegisterSet( pic_processor * picProcessor
 		m_nameToRegisterMap[ info->name() ] = info;
         qDebug() << Q_FUNC_INFO << " add register info " << info->name() << " at pos " << i << " addr " << info;
 	}
-#if defined(HAVE_GPSIM_0_26)
+#if 1 || defined(HAVE_GPSIM_0_26)
 	RegisterInfo * info = new RegisterInfo( picProcessor->Wreg ); // is tihs correct for "W" member? TODO
 #else
 	RegisterInfo * info = new RegisterInfo( picProcessor->W );
