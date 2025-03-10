--- common/options.c.orig	2023-09-25 08:47:42 UTC
+++ common/options.c
@@ -181,6 +181,8 @@ OPTLIST const optlist[] = {
 	{L("shellmeta"),	NULL,		OPT_STR,	0},
 /* O_SHIFTWIDTH	    4BSD */
 	{L("shiftwidth"),	NULL,		OPT_NUM,	OPT_NOZERO},
+/* O_SHOWFILENAME */
+	{L("showfilename"),	NULL,		OPT_0BOOL,	0},
 /* O_SHOWMATCH	    4BSD */
 	{L("showmatch"),	NULL,		OPT_0BOOL,	0},
 /* O_SHOWMODE	  4.4BSD */
@@ -317,7 +319,7 @@ opts_init(SCR *sp, int *oargs)
 	/* Set numeric and string default values. */
 #define	OI(indx, str) do {						\
 	a.len = STRLEN(str);						\
-	if ((CHAR_T*)str != b2)	  /* GCC puts strings in text-space. */	\
+	if (STRCMP((CHAR_T*)str, b2) != 0)					\
 		(void)MEMCPY(b2, str, a.len+1);				\
 	if (opts_set(sp, argv, NULL)) {					\
 		 optindx = indx;					\
