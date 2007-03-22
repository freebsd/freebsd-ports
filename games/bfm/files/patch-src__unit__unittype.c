--- ./src/unit/unittype.c.orig	Thu Apr 14 12:09:25 2005
+++ ./src/unit/unittype.c	Thu Mar 22 10:54:41 2007
@@ -263,7 +263,20 @@
 }
 
 	/// Macro to fetch an 8bit value, to have some looking 8/16/32 bit funcs.
-#define Fetch8(p)   (*((unsigned char*)(p))++)
+inline Uint8 Fetch8(Uint8 **p)
+{
+	return (*p++);
+}
+
+inline Uint16 FetchLE16(Uint16 **p)
+{
+	return (SDL_SwapLE16(*p++));
+}
+
+inline Uint32 FetchLE32(Uint32 **p)
+{
+	return (SDL_SwapLE32(*p++));
+}
 
 /**
 **		Parse UDTA area from puds.
