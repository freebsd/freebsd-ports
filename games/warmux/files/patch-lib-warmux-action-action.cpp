--- lib/warmux/action/action.cpp.orig	2012-02-13 22:38:00.000000000 +0100
+++ lib/warmux/action/action.cpp	2012-02-13 22:37:45.000000000 +0100
@@ -85,7 +85,7 @@
 {
   m_creator = _creator;
 
-  m_header.len = SDLNet_Read32(buffer);
+  m_header.len = SDLNet_Read32((Uint32*)buffer);
   ASSERT(m_header.len >= sizeof(Header));
   buffer += 4;
   // All of the following could be skipped for the actions we now,
