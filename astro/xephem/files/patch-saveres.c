--- saveres.c.orig	Thu Nov 30 07:01:20 2000
+++ saveres.c	Sat Dec 30 16:07:54 2000
@@ -1026,6 +1026,7 @@
 	    /* try mdovride else use default */
 	    FILE *ofp = fopenh (mdovride, "r");
 	    char *vp = NULL;
+	    char *vph;
 	    char nam[MRNAM], val[MRVAL], buf[MLL];
 
 	    if (ofp) {
@@ -1043,7 +1044,8 @@
 	    }
 	    if (!vp)
 		vp = mydirdef;
-	    mydir = XtNewString (expand_home(vp));
+	    vph = expand_home(vp);
+	    mydir = XtNewString (vph);
 	    if (access (mydir, X_OK) < 0 && mkdir (mydir, 0744) < 0) {
 		sprintf (buf, "%s: %s", mydir, syserrstr());
 		xe_msg (buf, 1);
