--- spectro/dispwin.c	2026-02-09 17:25:25.000000000 -0500
+++ spectro/dispwin.c	2026-04-25 21:46:10.494515000 -0400
@@ -760,5 +760,5 @@
 
 				primary = _XRRGetOutputPrimary(mydisplay, RootWindow(mydisplay,i));
-				debugrr2((errout,"XRRGetOutputPrimary returned XID %x\n",primary));
+				debugrr2((errout, "XRRGetOutputPrimary returned XID %lx\n", primary));
 
 				if (primary != None) {
@@ -1000,5 +1000,5 @@
 						Atom edid_atom, ret_type;
 						int ret_format;
-						long ret_len = 0, ret_togo;
+						unsigned long ret_len = 0, ret_togo;
 						unsigned char *atomv = NULL;
 						int ii;
@@ -1166,5 +1166,5 @@
 				Atom edid_atom, ret_type;
 				int ret_format = 8;
-				long ret_len, ret_togo;
+				unsigned long ret_len, ret_togo;
 				unsigned char *atomv = NULL;
 
@@ -1574,5 +1574,6 @@
 
 		if (nent != p->nent) {
-			debugr2((errout,"XF86VidModeGetGammaRampSize number of entries %d inconsistent with previous value\n",nent,p->nent));
+			debugr2((errout,"XF86VidModeGetGammaRampSize number of entries %d "
+			    "inconsistent with previous value of %d\n", nent, p->nent));
 			return NULL;
 		}
@@ -3567,5 +3568,5 @@
 		Atom ret_type;
 		int ret_format;
-		long ret_len, ret_togo;
+		unsigned long ret_len, ret_togo;
 		char aname[30];
 		unsigned char *atomv = NULL;	/* Profile loaded from/to atom */
@@ -5439,5 +5440,6 @@
 
 			if (depth != p->fdepth) {
-				debugr2((errout,"new_dispwin: Default Visual red mask 0x%x is not %d bits\n",vinfo->red_mask,p->fdepth));
+				debugr2((errout, "new_dispwin: Default Visual red mask 0x%lx is not %d bits\n",
+				    vinfo->red_mask, p->fdepth));
 				XFree(vinfo);
 				dispwin_del(p);
@@ -5452,5 +5454,6 @@
 
 			if (depth != p->fdepth) {
-				debugr2((errout,"new_dispwin: Default Visual green mask 0x%x is not %d bits\n",vinfo->red_mask,p->fdepth));
+				debugr2((errout, "new_dispwin: Default Visual green mask 0x%lx is not %d bits\n",
+				    vinfo->red_mask, p->fdepth));
 				XFree(vinfo);
 				dispwin_del(p);
@@ -5465,5 +5468,6 @@
 
 			if (depth != p->fdepth) {
-				debugr2((errout,"new_dispwin: Default Visual blue mask 0x%x is not %d bits\n",vinfo->red_mask,p->fdepth));
+				debugr2((errout, "new_dispwin: Default Visual blue mask 0x%lx is not %d bits\n",
+				    vinfo->red_mask, p->fdepth));
 				XFree(vinfo);
 				dispwin_del(p);
@@ -5700,5 +5704,4 @@
 				Atom optat;
 				unsigned int opaque = 0xffffffff;
-				unsigned int xid = (unsigned int)rootwindow;	/* Hope this is 32 bit */
 				XChangeProperty(
 					p->mydisplay, p->mywindow,
@@ -5707,5 +5710,5 @@
 					32,							/* format = bits in type of unsigned int */
 					PropModeReplace,			/* Change mode */
-					(char *)(&xid),				/* Data is Root Window XID */
+					(void *)(&rootwindow),				/* Data is Root Window XID */
 					1							/* Number of elements of data */
 				);
@@ -5714,9 +5717,9 @@
 				if ((optat = XInternAtom(p->mydisplay, "_NET_WM_WINDOW_OPACITY", False)) != None) {
 					XChangeProperty(p->mydisplay, p->mywindow, optat,
-	           				     XA_CARDINAL, 32, PropModeReplace, (char *)(&opaque), 1);
+	           				     XA_CARDINAL, 32, PropModeReplace, (void *)(&opaque), 1);
 				}
 				if ((optat = XInternAtom(p->mydisplay, "_NET_WM_WINDOW_OPACITY_LOCKED", False)) != None) {
 					XChangeProperty(p->mydisplay, p->mywindow, optat,
-	           				     XA_CARDINAL, 32, PropModeReplace, (char *)(&opaque), 1);
+	           				     XA_CARDINAL, 32, PropModeReplace, (void *)(&opaque), 1);
 				}
 			}
