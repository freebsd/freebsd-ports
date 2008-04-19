$FreeBSD$

--- ../../j2se/src/share/classes/com/sun/java/swing/plaf/gtk/Metacity.java.orig	Sun Dec 10 21:55:26 2006
+++ ../../j2se/src/share/classes/com/sun/java/swing/plaf/gtk/Metacity.java	Sun Dec 10 21:55:56 2006
@@ -456,8 +456,8 @@
 		String[] dirs = new String[] {
 		    userHome + sep + ".themes",
 		    System.getProperty("swing.metacitythemedir"),
-		    "/usr/X11R6/share/themes",
-		    "/usr/X11R6/share/gnome/themes",
+		    "%%LOCALBASE%%/share/themes",
+		    "%%LOCALBASE%%/share/gnome/themes",
 		    "/usr/share/themes",
 		    "/usr/gnome/share/themes",  // Debian/Redhat/Solaris
                     "/opt/gnome2/share/themes"  // SuSE
