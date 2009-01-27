--- include/sqltypes.h.orig	2008/10/31 16:22:18	1.26
+++ include/sqltypes.h	2008/11/27 13:44:43	1.27
@@ -49,7 +49,7 @@
  */
 
 #ifndef SIZEOF_LONG_INT
-#include <unixodbc_conf.h>
+#include "unixodbc_conf.h"
 #endif
 
 #ifndef SIZEOF_LONG_INT
@@ -371,10 +371,14 @@
 # if (SIZEOF_LONG_INT == 8)
 #   define ODBCINT64	    long
 #   define UODBCINT64	unsigned long
+#   define ODBCINT64_TYPE	    "long"
+#   define UODBCINT64_TYPE	"unsigned long"
 # else
 #  ifdef HAVE_LONG_LONG
 #   define ODBCINT64	    long long
 #   define UODBCINT64	unsigned long long
+#   define ODBCINT64_TYPE	    "long long"
+#   define UODBCINT64_TYPE	"unsigned long long"
 #  else
 /*
  * may fail in some cases, but what else can we do ?
@@ -391,6 +395,8 @@
 };
 #   define ODBCINT64	    struct __bigint_struct
 #   define UODBCINT64	struct __bigint_struct_u
+#   define ODBCINT64_TYPE	    "struct __bigint_struct"
+#   define UODBCINT64_TYPE	"struct __bigint_struct_u"
 #  endif
 # endif
 #endif
