--- ./st_wrap.c.orig    2008-02-01 17:58:38.381092000 -0800
+++ ./st_wrap.c 2008-02-01 17:59:52.092694956 -0800
@@ -227,6 +227,7 @@
 #include "EXTERN.h"
 #include "perl.h"
 #include "XSUB.h"
+#include "st.h"

 /* Get rid of free and malloc defined by perl */
 #undef free
