--- OgreMain/include/OgreUTFString.h.orig	2013-12-01 17:28:12 UTC
+++ OgreMain/include/OgreUTFString.h
@@ -188,10 +188,10 @@ namespace Ogre {
 		static const size_type npos = static_cast<size_type>(~0);
 
 		//! a single 32-bit Unicode character
-		typedef uint32 unicode_char;
+		typedef char32_t unicode_char;
 
 		//! a single UTF-16 code point
-		typedef uint16 code_point;
+		typedef char16_t code_point;
 
 		//! value type typedef for use in iterators
 		typedef code_point value_type;
