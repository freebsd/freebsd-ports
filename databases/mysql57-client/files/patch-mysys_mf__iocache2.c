--- mysys/mf_iocache2.c.orig	2018-10-28 11:22:04 UTC
+++ mysys/mf_iocache2.c
@@ -19,6 +19,7 @@
 
 #include "mysys_priv.h"
 #include "my_sys.h"
+#include "mysql/psi/mysql_file.h"
 #include <m_string.h>
 #include <stdarg.h>
 #include <m_ctype.h>
