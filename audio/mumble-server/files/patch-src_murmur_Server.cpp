--- src/murmur/Server.cpp.orig	2024-03-03 17:26:27 UTC
+++ src/murmur/Server.cpp
@@ -1041,7 +1041,7 @@ void Server::sendMessage(ServerUser &u, const unsigned
 			((reinterpret_cast< quint64 >(ebuffer.data()) + 8) & static_cast< quint64 >(~7)) + 4);
 #else
 		std::vector< char > bufVec;
-		bufVec.resize(len + 4);
+		bufVec.resize(static_cast< std::size_t >(len + 4));
 		char *buffer    = bufVec.data();
 #endif
 		{
