--- common/MultiString.h.orig	2007-11-13 22:48:04.000000000 +0100
+++ common/MultiString.h	2007-11-13 22:50:02.000000000 +0100
@@ -95,7 +95,7 @@
 	typedef	NAMESPACE(std) vector<T> list_t;
 	
 	TMString(unsigned int maxstr, const char *uniqueName,
-		char * const *defaultStr = 0L, kClassPersistent pclass = kNoClass);
+		const char * const *defaultStr = NULL, kClassPersistent pclass = kNoClass);
 		// defaultStr is a null terminated set of strings
 
 	virtual ~TMString();
@@ -134,7 +134,7 @@
 	UDECLARE_DYNAMIC(CMString)
 public:
 	CMString(unsigned int maxstr, const char *uniqueName,
-		char * const *defaultStr = 0L, kClassPersistent pclass = kNoClass) :
+		const char * const *defaultStr = NULL, kClassPersistent pclass = kNoClass) :
 		TMString<CStr>(maxstr, uniqueName, defaultStr, pclass)
 	{
 	}
