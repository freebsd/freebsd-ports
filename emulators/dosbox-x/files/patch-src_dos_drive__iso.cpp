Fix build with clang 19
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=282386

--- src/dos/drive_iso.cpp.orig	2024-10-02 06:16:36 UTC
+++ src/dos/drive_iso.cpp
@@ -40,6 +40,10 @@ extern bool CodePageHostToGuestUTF16(char *d/*CROSS_LE
 extern bool gbk, isDBCSCP(), isKanji1_gbk(uint8_t chr), shiftjis_lead_byte(int c);
 extern bool filename_not_8x3(const char *n), filename_not_strict_8x3(const char *n);
 extern bool CodePageHostToGuestUTF16(char *d/*CROSS_LEN*/,const uint16_t *s/*CROSS_LEN*/);
+inline bool CodePageHostToGuestUTF16(uint8_t *d/*CROSS_LEN*/,const uint8_t *s/*CROSS_LEN*/) {
+    std::u16string u16s(reinterpret_cast<const char16_t *>(s));
+    return CodePageHostToGuestUTF16(reinterpret_cast<char *>(d), reinterpret_cast<const uint16_t *>(u16s.c_str()));
+}
 
 using namespace std;
 
@@ -1762,7 +1766,7 @@ int isoDrive::readDirEntry(isoDirEntry* de, const uint
 				// The string is big Endian UCS-16, convert to host Endian UCS-16
 				for (size_t i=0;((const uint16_t*)de->ident)[i] != 0;i++) ((uint16_t*)de->ident)[i] = be16toh(((uint16_t*)de->ident)[i]);
 				// finally, convert from UCS-16 to local code page, using C++ string construction to make a copy first
-				CodePageHostToGuestUTF16((char*)de->ident,std::basic_string<uint16_t>((const uint16_t*)de->ident).c_str());
+				CodePageHostToGuestUTF16(de->ident, de->ident);
 			}
 		}
 	} else {
@@ -1784,7 +1788,7 @@ int isoDrive::readDirEntry(isoDirEntry* de, const uint
 			// The string is big Endian UCS-16, convert to host Endian UCS-16
 			for (size_t i=0;((const uint16_t*)de->ident)[i] != 0;i++) ((uint16_t*)de->ident)[i] = be16toh(((uint16_t*)de->ident)[i]);
 			// finally, convert from UCS-16 to local code page, using C++ string construction to make a copy first
-			CodePageHostToGuestUTF16((char*)de->ident,std::basic_string<uint16_t>((const uint16_t*)de->ident).c_str());
+			CodePageHostToGuestUTF16(de->ident, de->ident);
 		}
 		else {
 			// remove any file version identifiers as there are some cdroms that don't have them
