--- src/SocketAddr.c.orig	2020-11-30 18:53:55 UTC
+++ src/SocketAddr.c
@@ -87,6 +87,7 @@ void SockAddr_remoteAddr (struct thread_Settings *inSe
 	    inSettings->size_peer = sizeof(struct sockaddr_in);
 	}
 #else
+	}
         ((struct sockaddr*)&inSettings->peer)->sa_family = AF_INET;
 	inSettings->size_peer = sizeof(struct sockaddr_in);
 #endif
