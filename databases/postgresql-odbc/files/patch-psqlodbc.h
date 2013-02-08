--- psqlodbc.h.orig	2008-09-21 22:35:44.000000000 +0700
+++ psqlodbc.h	2009-01-26 23:19:02.000000000 +0600
@@ -151,13 +151,8 @@
 #if (SIZEOF_VOID_P == 8)
 #define	FORMAT_INTEGER	"%d"	/* SQLINTEGER */
 #define	FORMAT_UINTEGER	"%u"	/* SQLUINTEGER */
-#if defined(WITH_UNIXODBC) && !defined(BUILD_REAL_64_BIT_MODE)
-#define FORMAT_LEN	"%d"	/* SQLLEN */
-#define FORMAT_ULEN	"%u"	/* SQLULEN */
-#else
 #define FORMAT_LEN	"%ld"	/* SQLLEN */
 #define FORMAT_ULEN	"%lu"	/* SQLULEN */
-#endif /* WITH_UNIXODBC */
 #else
 #define	FORMAT_LEN	"%ld"	/* SQLLEN */
 #define	FORMAT_ULEN	"%lu"	/* SQLULEN */
