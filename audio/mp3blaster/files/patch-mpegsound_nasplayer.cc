nasplayer.cc:37:23: error: out-of-line definition of 'opendevice' does not match any declaration in 'NASplayer'
NASplayer *NASplayer::opendevice(char *server)
                      ^~~~~~~~~~
--- mpegsound/nasplayer.cc.orig	2017-06-06 00:05:37 UTC
+++ mpegsound/nasplayer.cc
@@ -34,7 +34,7 @@ NASplayer::~NASplayer()
 	}
 }
 
-NASplayer *NASplayer::opendevice(char *server)
+NASplayer *NASplayer::opendevice(const char *server)
 {
 	AuServer *aud;
 	char *return_status;
