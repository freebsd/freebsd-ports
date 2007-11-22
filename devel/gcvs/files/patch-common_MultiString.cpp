--- common/MultiString.cpp.orig	2007-11-13 23:07:12.000000000 +0100
+++ common/MultiString.cpp	2007-11-13 23:07:34.000000000 +0100
@@ -40,7 +40,7 @@
 #endif /* WIN32 */
 
 template<class T>
-TMString<T>::TMString(unsigned int maxstr, const char *uniqueName, char * const *defaultStr, 
+TMString<T>::TMString(unsigned int maxstr, const char *uniqueName, const char * const *defaultStr, 
 	kClassPersistent pclass) : CPersistent(uniqueName, pclass), fMaxStr(maxstr)
 {
 	if(defaultStr != 0L)
