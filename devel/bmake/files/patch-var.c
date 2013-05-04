------------------------------------------------------------------------
r250164 | sjg | 2013-05-02 02:58:39 +0300 (Thu, 02 May 2013) | 8 lines

Local hack to allow smooth transition for ports.
bsd.port.mk can set .MAKE.FreeBSD_UL=yes
to cause :L and :U to have their old behavior.
This should be reverted when 8.3 is EOL.

PR:		173299
Reviewed by:	obrien

--- var.c.orig	2013-03-04 03:01:57.000000000 +0200
+++ var.c	2013-05-04 10:28:21.832274582 +0300
@@ -140,6 +140,17 @@ __RCSID("$NetBSD: var.c,v 1.173 2013/02/
 #include    "job.h"
 
 /*
+ * XXX transition hack for FreeBSD ports.
+ * bsd.port.mk can set .MAKE.FreeBSD_UL=yes
+ * to cause us to treat :[LU] as aliases for :t[lu]
+ * To be reverted when ports converts to :t[lu] (when 8.3 is EOL)
+ */
+#define MAKE_FREEBSD_UL ".MAKE.FreeBSD_UL"
+#ifdef MAKE_FREEBSD_UL
+static int FreeBSD_UL = FALSE;
+#endif
+
+/*
  * This lets us tell if we have replaced the original environ
  * (which we cannot free).
  */
@@ -965,6 +976,11 @@ Var_Set(const char *name, const char *va
 	setenv(MAKE_LEVEL_SAFE, tmp, 1);
 #endif
     }
+#ifdef MAKE_FREEBSD_UL
+    if (strcmp(MAKE_FREEBSD_UL, name) == 0) {
+	FreeBSD_UL = getBoolean(MAKE_FREEBSD_UL, FALSE);
+    }
+#endif
 	
 	
  out:
@@ -2660,8 +2676,24 @@ ApplyModifiers(char *nstr, const char *t
 		free(loop.str);
 		break;
 	    }
-	case 'D':
 	case 'U':
+#ifdef MAKE_FREEBSD_UL
+	    if (FreeBSD_UL) {
+		int nc = tstr[1];
+
+		/* we have to be careful, since :U is used internally */
+		if (nc == ':' || nc == endc) {
+		    char *dp = bmake_strdup(nstr);
+		    for (newStr = dp; *dp; dp++)
+			*dp = toupper((unsigned char)*dp);
+		    cp = tstr + 1;
+		    termc = *cp;
+		    break;		/* yes inside the conditional */
+		}
+		/* FALLTHROUGH */
+	    }
+#endif
+	case 'D':
 	    {
 		Buffer  buf;    	/* Buffer for patterns */
 		int	    wantit;	/* want data in buffer */
@@ -2721,6 +2753,17 @@ ApplyModifiers(char *nstr, const char *t
 		break;
 	    }
 	case 'L':
+#ifdef MAKE_FREEBSD_UL
+	    if (FreeBSD_UL) {
+		char *dp = bmake_strdup(nstr);
+		for (newStr = dp; *dp; dp++)
+		    *dp = tolower((unsigned char)*dp);
+		cp = tstr + 1;
+		termc = *cp;
+		break;
+	    }
+	    /* FALLTHROUGH */
+#endif
 	    {
 		if ((v->flags & VAR_JUNK) != 0)
 		    v->flags |= VAR_KEEP;
