--- ../libdbf/include/libdbf/libdbf.h.orig
+++ ../libdbf/include/libdbf/libdbf.h
@@ -17,6 +17,9 @@
  * $Id: libdbf.h,v 1.6 2006/04/14 12:25:30 rollinhand Exp $
  ****************************************************************************/
 
+#ifndef __LIBDBF_H__
+#define __LIBDBF_H__
+
 #include <sys/types.h>
 
 /*! \file libdbf.h
@@ -337,3 +340,4 @@
 */
 int dbf_IsMemo(P_DBF *p_dbf);
 
+#endif /* __LIBDBF_H__ */
