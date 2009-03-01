--- src/macro.h.orig	2009-03-01 20:11:52.000000000 +0800
+++ src/macro.h	2009-03-01 20:12:31.000000000 +0800
@@ -2,6 +2,7 @@
  * Copyright (C) 1992,1993 NEC Corporation.
  * $Id: macro.h,v 2.6 1994/04/19 10:16:49 uchida Exp $ (NEC)
  */
+#define	MAX_MACRO_LEN	320
 #define	MACRO_MAXARG	10
 
 #define	M_DOC_BEGIN	0
@@ -74,5 +75,5 @@
 
 struct	macDefs {
 	int	mdef_number;
-	char	*mdef_def;
+	char	mdef_def[MAX_MACRO_LEN];
 };
