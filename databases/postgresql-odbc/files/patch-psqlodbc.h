--- psqlodbc.h.orig	2017-02-03 13:05:10 UTC
+++ psqlodbc.h
@@ -174,13 +174,8 @@ typedef	unsigned long long ULONG_PTR;
 #define	FORMAT_UINTEGER	"%u"	/* SQLUINTEGER */
 #define	FORMATI64	"%ld"	/* SQLBIGINT */
 #define	FORMATI64U	"%lu"	/* SQLUBIGINT */
-#if defined(WITH_UNIXODBC) && defined(BUILD_LEGACY_64_BIT_MODE)
-#define FORMAT_LEN	"%d"	/* SQLLEN */
-#define FORMAT_ULEN	"%u"	/* SQLULEN */
-#else /* WITH_UNIXODBC */
 #define FORMAT_LEN	"%ld"	/* SQLLEN */
 #define FORMAT_ULEN	"%lu"	/* SQLULEN */
-#endif /* WITH_UNIXODBC */
 #else /* SIZEOF_LONG */
 #define	FORMAT_INTEGER	"%ld"	/* SQLINTEGER */
 #define	FORMAT_UINTEGER	"%lu"	/* SQLUINTEGER */
