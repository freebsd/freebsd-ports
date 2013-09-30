--- src/jrd/unicode_util.cpp	2013-03-19 03:38:19.000000000 -0500
+++ src/jrd/unicode_util.cpp	2013-09-05 08:59:56.000000000 -0500
@@ -42,6 +42,9 @@
 #include "unicode/ucnv.h"
 #include "unicode/ucol.h"
 
+// The next major ICU version after 4.8 is 49.
+#define ICU_NEW_VERSION_MEANING	49
+
 
 using namespace Firebird;
 
@@ -49,8 +52,16 @@
 namespace Jrd {
 
 
+#if U_ICU_VERSION_MAJOR_NUM >= ICU_NEW_VERSION_MEANING
+const char* const UnicodeUtil::DEFAULT_ICU_VERSION = STRINGIZE(U_ICU_VERSION_MAJOR_NUM);
+#else
 const char* const UnicodeUtil::DEFAULT_ICU_VERSION =
 	STRINGIZE(U_ICU_VERSION_MAJOR_NUM)"."STRINGIZE(U_ICU_VERSION_MINOR_NUM);
+#endif
+
+
+static void formatFilename(PathName& filename, const char* templateName,
+	int majorVersion, int minorVersion);
 
 
 // encapsulate ICU collations libraries
@@ -65,12 +76,16 @@
 		: majorVersion(aMajorVersion),
 		  minorVersion(aMinorVersion),
 		  inModule(NULL),
-		  ucModule(NULL)
+		  ucModule(NULL),
+		  ciAiTransCache(*getDefaultMemoryPool())
 	{
 	}
 
 	~ICU()
 	{
+		while (ciAiTransCache.hasData())
+			utransClose(ciAiTransCache.pop());
+
 		delete ucModule;
 		delete inModule;
 	}
@@ -79,6 +94,11 @@
 	{
 		string symbol;
 
+		symbol.printf("%s_%d", name, majorVersion);
+		module->findSymbol(symbol, ptr);
+		if (ptr)
+			return;
+
 		symbol.printf("%s_%d_%d", name, majorVersion, minorVersion);
 		module->findSymbol(symbol, ptr);
 		if (ptr)
@@ -86,6 +106,40 @@
 
 		symbol.printf("%s_%d%d", name, majorVersion, minorVersion);
 		module->findSymbol(symbol, ptr);
+		if (ptr)
+			return;
+
+		symbol.printf("%s", name);
+		module->findSymbol(symbol, ptr);
+	}
+
+	UTransliterator* getCiAiTransliterator()
+	{
+		ciAiTransCacheMutex.enter();
+		UTransliterator* ret;
+
+		if (!ciAiTransCache.isEmpty())
+		{
+			ret = ciAiTransCache.pop();
+			ciAiTransCacheMutex.leave();
+		}
+		else
+		{
+			ciAiTransCacheMutex.leave();
+
+			UErrorCode errorCode = U_ZERO_ERROR;
+			// Fix for CORE-4136. Was "Any-Upper; NFD; [:Nonspacing Mark:] Remove; NFC".
+			ret = utransOpen("NFD; [:Nonspacing Mark:] Remove; NFC",
+				UTRANS_FORWARD, NULL, 0, NULL, &errorCode);
+		}
+
+		return ret;
+	}
+
+	void releaseCiAiTransliterator(UTransliterator* trans)
+	{
+		MutexLockGuard guard(ciAiTransCacheMutex);
+		ciAiTransCache.push(trans);
 	}
 
 	int majorVersion;
@@ -93,6 +147,8 @@
 	ModuleLoader::Module* inModule;
 	ModuleLoader::Module* ucModule;
 	UVersionInfo collVersion;
+	Mutex ciAiTransCacheMutex;
+	Array<UTransliterator*> ciAiTransCache;
 
 	void (U_EXPORT2 *uInit)(UErrorCode* status);
 	void (U_EXPORT2 *uVersionToString)(UVersionInfo versionArray, char* versionString);
@@ -157,14 +213,25 @@
 	RWLock lock;
 };
 
-namespace {
-	GlobalPtr<UnicodeUtil::ICUModules> icuModules;
-}
+static GlobalPtr<UnicodeUtil::ICUModules> icuModules;
 
 
 static const char* const COLL_30_VERSION = "41.128.4.4";	// ICU 3.0 collator version
 
 
+static void formatFilename(PathName& filename, const char* templateName,
+	int majorVersion, int minorVersion)
+{
+	string s;
+	if (majorVersion >= ICU_NEW_VERSION_MEANING)
+		s.printf("%d", majorVersion);
+	else
+		s.printf("%d%d", majorVersion, minorVersion);
+
+	filename.printf(templateName, s.c_str());
+}
+
+
 static void getVersions(const string& configInfo, ObjectsArray<string>& versions)
 {
 	charset cs;
@@ -758,17 +825,17 @@
 	const Firebird::string& configInfo)
 {
 #if defined(WIN_NT)
-	const char* const inTemplate = "icuin%d%d.dll";
-	const char* const ucTemplate = "icuuc%d%d.dll";
+	const char* const inTemplate = "icuin%s.dll";
+	const char* const ucTemplate = "icuuc%s.dll";
 #elif defined(DARWIN)
 	const char* const inTemplate = "/Library/Frameworks/Firebird.framework/Versions/A/Libraries/libicui18n.dylib";
 	const char* const ucTemplate = "/Library/Frameworks/Firebird.framework/versions/A/Libraries/libicuuc.dylib";
 #elif defined(HPUX)
-	const char* const inTemplate = "libicui18n.sl.%d%d";
-	const char* const ucTemplate = "libicuuc.sl.%d%d";
+	const char* const inTemplate = "libicui18n.sl.%s";
+	const char* const ucTemplate = "libicuuc.sl.%s";
 #else
-	const char* const inTemplate = "libicui18n.so.%d%d";
-	const char* const ucTemplate = "libicuuc.so.%d%d";
+	const char* const inTemplate = "libicui18n.so.%s";
+	const char* const ucTemplate = "libicuuc.so.%s";
 #endif
 
 	ObjectsArray<string> versions;
@@ -776,24 +843,28 @@
 
 	string version = icuVersion.isEmpty() ? versions[0] : icuVersion;
 	if (version == "default")
-	{
-		version.printf("%d.%d", U_ICU_VERSION_MAJOR_NUM, U_ICU_VERSION_MINOR_NUM);
-	}
+		version = DEFAULT_ICU_VERSION;
 
 	for (ObjectsArray<string>::const_iterator i(versions.begin()); i != versions.end(); ++i)
 	{
 		int majorVersion, minorVersion;
+		int n = sscanf((*i == "default" ? version : *i).c_str(), "%d.%d",
+			&majorVersion, &minorVersion);
 
-		if (*i == "default")
-		{
-			majorVersion = U_ICU_VERSION_MAJOR_NUM;
-			minorVersion = U_ICU_VERSION_MINOR_NUM;
-		}
-		else if (sscanf(i->c_str(), "%d.%d", &majorVersion, &minorVersion) != 2)
+		if (n == 1)
+			minorVersion = 0;
+		else if (n != 2)
 			continue;
 
 		string configVersion;
-		configVersion.printf("%d.%d", majorVersion, minorVersion);
+
+		if (majorVersion >= ICU_NEW_VERSION_MEANING)
+		{
+			minorVersion = 0;
+			configVersion.printf("%d", majorVersion);
+		}
+		else
+			configVersion.printf("%d.%d", majorVersion, minorVersion);
 
 		if (version != configVersion)
 			continue;
@@ -805,7 +876,7 @@
 			return icu;
 
 		PathName filename;
-		filename.printf(ucTemplate, majorVersion, minorVersion);
+		formatFilename(filename, ucTemplate, majorVersion, minorVersion);
 
 		icu = FB_NEW(*getDefaultMemoryPool()) ICU(majorVersion, minorVersion);
 
@@ -822,7 +893,7 @@
 			continue;
 		}
 
-		filename.printf(inTemplate, majorVersion, minorVersion);
+		formatFilename(filename, inTemplate, majorVersion, minorVersion);
 
 		icu->inModule = ModuleLoader::loadModule(filename);
 		if (!icu->inModule)
@@ -1208,44 +1279,40 @@
 ULONG UnicodeUtil::Utf16Collation::canonical(ULONG srcLen, const USHORT* src, ULONG dstLen, ULONG* dst,
 	const ULONG* exceptions)
 {
+	fb_assert(srcLen % sizeof(*src) == 0);
+
 	HalfStaticArray<USHORT, BUFFER_SMALL / 2> upperStr;
 
-	if ((attributes & (TEXTTYPE_ATTR_CASE_INSENSITIVE | TEXTTYPE_ATTR_ACCENT_INSENSITIVE)) ==
-		(TEXTTYPE_ATTR_CASE_INSENSITIVE | TEXTTYPE_ATTR_ACCENT_INSENSITIVE))
+	if (attributes & TEXTTYPE_ATTR_CASE_INSENSITIVE)
 	{
-		fb_assert(srcLen % sizeof(*src) == 0);
-
-		memcpy(upperStr.getBuffer(srcLen / sizeof(USHORT)), src, srcLen);
-
-		UErrorCode errorCode = U_ZERO_ERROR;
-		UTransliterator* trans = icu->utransOpen("Any-Upper; NFD; [:Nonspacing Mark:] Remove; NFC",
-			UTRANS_FORWARD, NULL, 0, NULL, &errorCode);
+		srcLen = utf16UpperCase(srcLen, src, srcLen,
+			upperStr.getBuffer(srcLen / sizeof(USHORT)), NULL);
+		src = upperStr.begin();
 
-		if (errorCode <= 0)
+		if (attributes & TEXTTYPE_ATTR_ACCENT_INSENSITIVE)
 		{
-			const int32_t capacity = upperStr.getCount();
-			int32_t len = srcLen / sizeof(USHORT);
-			int32_t limit = len;
-
-			icu->utransTransUChars(trans, reinterpret_cast<UChar*>(upperStr.begin()),
-				&len, capacity, 0, &limit, &errorCode);
-			icu->utransClose(trans);
+			UTransliterator* trans = icu->getCiAiTransliterator();
 
-			len *= sizeof(USHORT);
-			if (ULONG(len) > dstLen)
-				len = INTL_BAD_STR_LENGTH;
+			if (trans)
+			{
+				const int32_t capacity = upperStr.getCount();
+				int32_t len = srcLen / sizeof(USHORT);
+				int32_t limit = len;
+
+				UErrorCode errorCode = U_ZERO_ERROR;
+				icu->utransTransUChars(trans, reinterpret_cast<UChar*>(upperStr.begin()),
+					&len, capacity, 0, &limit, &errorCode);
+				icu->releaseCiAiTransliterator(trans);
+
+				len *= sizeof(USHORT);
+				if (ULONG(len) > dstLen)
+					len = INTL_BAD_STR_LENGTH;
 
-			srcLen = len;
-			src = upperStr.begin();
+				srcLen = len;
+			}
+			else
+				return INTL_BAD_STR_LENGTH;
 		}
-		else
-			return INTL_BAD_STR_LENGTH;
-	}
-	else if (attributes & TEXTTYPE_ATTR_CASE_INSENSITIVE)
-	{
-		srcLen = utf16UpperCase(srcLen, src,
-			srcLen, upperStr.getBuffer(srcLen / sizeof(USHORT)), exceptions);
-		src = upperStr.begin();
 	}
 
 	// convert UTF-16 to UTF-32
