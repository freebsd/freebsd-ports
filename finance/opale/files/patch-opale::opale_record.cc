--- opale/opale_record.cc.orig	Thu Nov 20 12:00:53 2003
+++ opale/opale_record.cc	Sun Feb 29 22:18:25 2004
@@ -270,7 +270,7 @@
 		QString("%1 %2").arg( QString().sprintf("%12.2f", m_amount/100.)).arg(currency),
 		checked()?"X":"",
 		howlist[type],
-		isFutur()?i18n("Future"):"",
+		isFutur()?i18n("Future"):QString(""),
 		QString("%1 %2").arg( QString().sprintf("%12.2f", t->global/100.)).arg(currency),
 		categorylist[category] );
 
@@ -324,10 +324,19 @@
 
 #ifndef USE_BUGGY_STRTOD
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #include <stdlib.h>
 #include <ctype.h>
 #include <math.h>
+
+#if (defined(BSD) && (BSD >= 199306))
+#include <limits.h>
+#else
 #include <values.h> 	// MAXLONG
+#endif
 
 amount_t
 atoprice (const char *buf)
@@ -347,7 +356,11 @@
       a = atol (buf);
  
       /* provisoire */
+#if (defined(BSD) && (BSD >= 199306))
+      if (a > ((LONG_MAX) / 100))
+#else
       if (a > MAXLONG / 100)
+#endif
 	kdDebug(OPALE_DEBUG_STREAM) << "Price out of limits(1)" << endl;
  
       return (a >= 0) ? 100 * a + b : 100 * a - b;
@@ -356,7 +369,11 @@
     {
       /* provisoire */
       a = atol (buf);
+#if (defined(BSD) && (BSD >= 199306))
+      if (a > ((LONG_MAX) / 100))
+#else
       if (a > ((MAXLONG) / 100))
+#endif
         kdDebug(OPALE_DEBUG_STREAM) << "Price out of limits(2)" << endl;
       return (100 * a);
     }
