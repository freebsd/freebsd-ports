--- print.c.org	Thu Feb  1 10:46:22 2001
+++ print.c	Thu Feb  1 10:47:00 2001
@@ -34,7 +34,7 @@
 
 #define PS_LIB		"plan_cal.ps"
 #ifdef JAPAN
-#define PS_LIB_SJ	"plan_calSJ.ps"
+#define PS_LIB_EUC	"plan_calEUC.ps"
 extern char		*localename;
 #endif
 #ifdef BSD
@@ -521,7 +521,7 @@
 #ifdef JAPAN
 	if (strcmp(localename, LOCALE_SJIS) == 0 ||
 	    strcmp(localename, LOCALE_EUC) == 0)
-		find_file(PsLib, PS_LIB_SJ, FALSE);
+		find_file(PsLib, PS_LIB_EUC, FALSE);
 	else
 #endif
 	find_file(PsLib, PS_LIB, FALSE);
