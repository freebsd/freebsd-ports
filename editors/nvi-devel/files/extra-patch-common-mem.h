--- ../common/mem.h.orig	2000-08-20 05:12:59.000000000 -0400
+++ ../common/mem.h	2007-11-15 13:55:35.000000000 -0500
@@ -13,7 +13,7 @@
  * returns, one that jumps to an error label.
  */
 #define	BINC_GOTO(sp, lp, llen, nlen) {					\
-	char *L__p = lp;						\
+	CHAR_T *L__p = lp;						\
 	void *L__bincp;							\
 	if ((nlen) > llen) {						\
 		if ((L__bincp = binc(sp, lp, &(llen), nlen)) == NULL)	\
@@ -25,12 +25,12 @@
 		lp = L__bincp;						\
 	}								\
 }
-#define	BINC_GOTOW(sp, lp, llen, nlen) {					\
+#define	BINC_GOTOW(sp, lp, llen, nlen) {				\
 	CHAR_T *L__bp = lp;						\
-	BINC_GOTO(sp, (char *)lp, llen, (nlen) * sizeof(CHAR_T))    	\
+	BINC_GOTO(sp, lp, llen, (nlen) * sizeof(CHAR_T))	    	\
 }
 #define	BINC_RET(sp, lp, llen, nlen) {					\
-	char *L__p = lp;						\
+	CHAR_T *L__p = lp;						\
 	void *L__bincp;							\
 	if ((nlen) > llen) {						\
 		if ((L__bincp = binc(sp, lp, &(llen), nlen)) == NULL)	\
@@ -44,7 +44,7 @@
 }
 #define	BINC_RETW(sp, lp, llen, nlen) {					\
 	CHAR_T *L__bp = lp;						\
-	BINC_RET(sp, (char *)lp, llen, (nlen) * sizeof(CHAR_T))	    	\
+	BINC_RET(sp, lp, llen, (nlen) * sizeof(CHAR_T))	    		\
 }
 
 /*
@@ -67,7 +67,7 @@
 }
 #define	GET_SPACE_GOTOW(sp, bp, blen, nlen) {				\
 	CHAR_T *L__bp = bp;						\
-	GET_SPACE_GOTO(sp, (char *)bp, blen, (nlen) * sizeof(CHAR_T))	\
+	GET_SPACE_GOTO(sp, bp, blen, (nlen) * sizeof(CHAR_T))		\
 }
 #define	GET_SPACE_RET(sp, bp, blen, nlen) {				\
 	WIN *L__wp = (sp) == NULL ? NULL : (sp)->wp;			\
@@ -84,7 +84,7 @@
 }
 #define	GET_SPACE_RETW(sp, bp, blen, nlen) {				\
 	CHAR_T *L__bp = bp;						\
-	GET_SPACE_RET(sp, (char *)bp, blen, (nlen) * sizeof(CHAR_T))	\
+	GET_SPACE_RET(sp, bp, blen, (nlen) * sizeof(CHAR_T))		\
 }
 
 /*
@@ -104,7 +104,7 @@
 }
 #define	ADD_SPACE_GOTOW(sp, bp, blen, nlen) {				\
 	CHAR_T *L__bp = bp;						\
-	ADD_SPACE_GOTO(sp, (char *)bp, blen, (nlen) * sizeof(CHAR_T))	\
+	ADD_SPACE_GOTO(sp, bp, blen, (nlen) * sizeof(CHAR_T))		\
 }
 #define	ADD_SPACE_RET(sp, bp, blen, nlen) {				\
 	WIN *L__wp = (sp) == NULL ? NULL : (sp)->wp;			\
@@ -119,7 +119,7 @@
 }
 #define	ADD_SPACE_RETW(sp, bp, blen, nlen) {				\
 	CHAR_T *L__bp = bp;						\
-	ADD_SPACE_RET(sp, (char *)bp, blen, (nlen) * sizeof(CHAR_T))	\
+	ADD_SPACE_RET(sp, bp, blen, (nlen) * sizeof(CHAR_T))		\
 }
 
 /* Free a GET_SPACE returned buffer. */
@@ -132,7 +132,7 @@
 }
 #define	FREE_SPACEW(sp, bp, blen) {					\
 	CHAR_T *L__bp = bp;						\
-	FREE_SPACE(sp, (char *)bp, blen);				\
+	FREE_SPACE(sp, bp, blen);					\
 }
 
 /*
