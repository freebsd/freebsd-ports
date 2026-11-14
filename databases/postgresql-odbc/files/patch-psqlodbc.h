--- psqlodbc.h.orig	2026-11-02 18:01:24 UTC
+++ psqlodbc.h
@@ -263,17 +263,10 @@ typedef	unsigned long long ULONG_PTR;
 #define	FORMAT_UINTEGER	"%u"	/* SQLUINTEGER */
 #define	FORMATI64	"%ld"	/* SQLBIGINT */
 #define	FORMATI64U	"%lu"	/* SQLUBIGINT */
-#if defined(WITH_UNIXODBC) && defined(BUILD_LEGACY_64_BIT_MODE)
-#define FORMAT_LEN	"%d"	/* SQLLEN */
-#define FORMAT_ULEN	"%u"	/* SQLULEN */
-#define	ARG_FORMAT_LEN	ARG_INT
-#define	ARG_FORMAT_ULEN	ARG_UINT
-#else /* WITH_UNIXODBC */
 #define FORMAT_LEN	"%ld"	/* SQLLEN */
 #define FORMAT_ULEN	"%lu"	/* SQLULEN */
 #define	ARG_FORMAT_LEN	ARG_LONG
 #define	ARG_FORMAT_ULEN	ARG_ULONG
-#endif /* WITH_UNIXODBC */
 #else /* SIZEOF_LONG */
 #define	FORMAT_INTEGER	"%ld"	/* SQLINTEGER */
 #define	FORMAT_UINTEGER	"%lu"	/* SQLUINTEGER */
