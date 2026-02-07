--- ./Alias.xs.orig	1999-05-01 02:11:09.000000000 +0000
+++ ./Alias.xs	2012-03-07 03:17:05.659746489 +0000
@@ -21,6 +21,13 @@
 
 #endif
 
+#ifndef GvCV_set
+#  define GvCV_set(gv,cv)   (GvGP(gv)->gp_cv = (cv))
+#endif
+#ifndef GvGP_set
+#  define GvGP_set(gv,gp)   ((gv)->sv_u.svu_gp = (gp))
+#endif
+
 static void process_flag _((char *varname, SV **svp, char **strp, STRLEN *lenp));
 
 static void
@@ -205,8 +212,8 @@
 			save_gp(gv,TRUE);   /* hide previous entry in symtab */
 			break;
 		    case SVt_PVCV:
-			SAVESPTR(GvCV(gv));
-			GvCV(gv) = Null(CV*);
+			SAVESPTR(GvGP(gv)->gp_cv);
+                        GvCV_set(gv,Null(CV*));
 			break;
 		    default:
 			save_scalar(gv);
