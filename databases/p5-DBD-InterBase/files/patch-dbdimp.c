--- dbdimp.c	Thu Aug 29 06:28:30 2002
+++ dbi-interbase/dbdimp.c	Thu Sep 12 12:15:32 2002
@@ -1,5 +1,5 @@
 /*
-   $Id: dbdimp.c,v 1.96 2002/08/12 16:04:26 danielritz Exp $
+   $Id: dbdimp.c,v 1.97 2002/09/10 13:30:07 danielritz Exp $
 
    Copyright (c) 1999-2002  Edwin Pratomo
    Portions Copyright (c) 2001-2002  Daniel Ritz
@@ -1329,7 +1329,10 @@
 #elif defined(__BORLANDC__)  /* Borland compiler/library */
 #  define P_INT64_RPEC "%.*Lf"
 #  define P_INT64_FULL "%s%Ld%s"
-#else                        /* others: linux, xBSD, solaris, hp-ux, ... */
+#elif defined (__FreeBSD__)  /* FreeBSD */
+#  define P_INT64_RPEC "%.*Lf"
+#  define P_INT64_FULL "%s%qd%s"
+#else                        /* others: linux, various unices */
 #  define P_INT64_RPEC "%.*Lf"
 #  define P_INT64_FULL "%s%lld%s"
 #endif
@@ -2429,7 +2432,12 @@
 #  define S_INT64_NOSCALE     "%%Ld.%%1Ld"
 #  define S_INT64_DEC_FULL    ".%%%dLd%%1Ld"
 #  define S_INT64_DEC_NOSCALE ".%%1Ld"
-#else                        /* others: linux, xBSD, solaris, hp-ux, ... */
+#elif defined (__FreeBSD__)  /* FreeBSD */
+#  define S_INT64_FULL        "%%qd.%%%dqd%%1qd"
+#  define S_INT64_NOSCALE     "%%qd.%%1qd"
+#  define S_INT64_DEC_FULL    ".%%%dqd%%1qd"
+#  define S_INT64_DEC_NOSCALE ".%%1qd"
+#else                        /* others: linux, various unices */
 #  define S_INT64_FULL        "%%lld.%%%dlld%%1lld"
 #  define S_INT64_NOSCALE     "%%lld.%%1lld"
 #  define S_INT64_DEC_FULL    ".%%%dlld%%1lld"
