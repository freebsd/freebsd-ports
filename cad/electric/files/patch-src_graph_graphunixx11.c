--- src/graph/graphunixx11.c.orig	2004-07-16 01:59:53 UTC
+++ src/graph/graphunixx11.c
@@ -167,6 +167,8 @@
 #define TRUESTRLEN strlen
 
 
+#include <sys/sysctl.h>
+
 /****** windows ******/
 
 #define WMLEFTBORDER         8					/* size of left border for windows */
@@ -1518,13 +1520,13 @@ BOOLEAN initgraphics(BOOLEAN messages)
 		gra_truetypeon = 1;
 
 		/* Preload T1 fonts here, because T1_LoadFont spoils memory */
-		for(j=0; j<T1_Get_no_fonts(); j++) T1_LoadFont(j);
+		for(j=0; j<T1_GetNoFonts(); j++) T1_LoadFont(j);
 
 		gra_truetypedeffont = 0;		/* presume that the first font is good to use */
 		ptr = egetenv(x_("ELECTRIC_TRUETYPE_FONT"));
 		if (ptr != NULL)
 		{
-			j = T1_Get_no_fonts();
+			j = T1_GetNoFonts();
 			for(gra_truetypedeffont=0; gra_truetypedeffont<j; gra_truetypedeffont++)
 			{
 				T1_LoadFont(gra_truetypedeffont);
@@ -3088,8 +3090,13 @@ void ewait(INTBIG process)
 INTBIG enumprocessors(void)
 {
 	INTBIG numproc;
+	size_t proclen;
+ 
+	proclen = sizeof(numproc);
+	if ((sysctlbyname("hw.ncpu", &numproc, &proclen, NULL, 0) < 0) ||
+	   (proclen != sizeof(numproc)))
+		numproc = 1;
 
-	numproc = sysconf(_SC_NPROCESSORS_ONLN);
 	return(numproc);
 }
 
@@ -4758,7 +4765,7 @@ INTBIG screengetfacelist(CHAR ***list, B
 
 	if (gra_numfaces == 0)
 	{
-		total = T1_Get_no_fonts();
+		total = T1_GetNoFonts();
 		gra_numfaces = total + 1;
 		gra_facelist = (CHAR **)emalloc(gra_numfaces * (sizeof (CHAR *)), us_tool->cluster);
 		if (gra_facelist == 0) return(0);
