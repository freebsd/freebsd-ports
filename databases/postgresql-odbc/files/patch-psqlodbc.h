--- psqlodbc.h.orig	2016-01-10 13:25:14 UTC
+++ psqlodbc.h
@@ -175,13 +175,8 @@ typedef	unsigned long long ULONG_PTR;
 #if (SIZEOF_LONG == 8)
 #define	FORMAT_INTEGER	"%d"	/* SQLINTEGER */
 #define	FORMAT_UINTEGER	"%u"	/* SQLUINTEGER */
-#if defined(WITH_UNIXODBC) && defined(BUILD_LEGACY_64_BIT_MODE)
-#define FORMAT_LEN	"%d"	/* SQLLEN */
-#define FORMAT_ULEN	"%u"	/* SQLULEN */
-#else
 #define FORMAT_LEN	"%ld"	/* SQLLEN */
 #define FORMAT_ULEN	"%lu"	/* SQLULEN */
-#endif /* WITH_UNIXODBC */
 #else
 #define	FORMAT_LEN	"%ld"	/* SQLLEN */
 #define	FORMAT_ULEN	"%lu"	/* SQLULEN */
