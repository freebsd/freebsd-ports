--- mysys/mf_iocache2.c.orig	2019-02-18 09:11:31.000000000 +0300
+++ mysys/mf_iocache2.c
@@ -24,6 +24,7 @@
 #include <m_string.h>
 #include <stdarg.h>
 #include <m_ctype.h>
+#include "mysql/psi/mysql_file.h"
 
 /*
   Copy contents of an IO_CACHE to a file.
