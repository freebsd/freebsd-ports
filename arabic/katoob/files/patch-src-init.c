--- src/init.c	Tue Aug 26 07:54:35 2003
+++ /home/samy/development/katoob/src/init.c	Thu Aug 28 00:36:48 2003
@@ -101,7 +101,18 @@
 		  katoob->xkb_grps[i] =
 		    XGetAtomName (GDK_DISPLAY (), kbinfo->names->groups[i]);
 		}
+	      else
+		{
+		  katoob->xkb_grps[i] = NULL;
+		}
 	    }
+	}
+
+/* Let's NULL all the remaining array. */
+      while (grpnum < XkbNumKbdGroups)
+	{
+	  katoob->xkb_grps[grpnum] = NULL;
+	  ++grpnum;
 	}
 
       XkbGetControls (GDK_DISPLAY (), XkbAllControlsMask, kbinfo);
