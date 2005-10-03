--- Eris/BaseConnection.cpp.orig	Mon Oct  3 18:14:51 2005
+++ Eris/BaseConnection.cpp	Mon Oct  3 18:15:28 2005
@@ -156,7 +156,7 @@
     _timeout = new Timeout("negotiate_" + _id, this, 5000);
     _timeout->Expired.connect(SigC::slot(*this, &BaseConnection::onNegotiateTimeout));
 
-    _sc = new Atlas::Net::StreamConnect(_clientName, *_stream, *_bridge);
+    _sc = new Atlas::Net::StreamConnect(_clientName, *_stream);
     setStatus(NEGOTIATE);
 }
 
@@ -174,7 +174,7 @@
 	
     if (_sc->getState() == Atlas::Net::StreamConnect::SUCCEEDED)
     {
-        m_codec = _sc->getCodec();
+        m_codec = _sc->getCodec(*_bridge);
         _encode = new Atlas::Objects::ObjectsEncoder(*m_codec);
         m_codec->streamBegin();
         // clean up
