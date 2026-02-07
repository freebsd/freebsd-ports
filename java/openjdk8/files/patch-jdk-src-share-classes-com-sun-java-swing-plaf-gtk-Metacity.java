--- jdk/src/share/classes/com/sun/java/swing/plaf/gtk/Metacity.java
+++ jdk/src/share/classes/com/sun/java/swing/plaf/gtk/Metacity.java
@@ -477,10 +477,8 @@
                 String[] dirs = new String[] {
                     userHome + sep + ".themes",
                     System.getProperty("swing.metacitythemedir"),
-                    "/usr/X11R6/share/themes",
-                    "/usr/X11R6/share/gnome/themes",
-                    "/usr/local/share/themes",
-                    "/usr/local/share/gnome/themes",
+                    "%%LOCALBASE%%/share/themes",
+                    "%%LOCALBASE%%/share/gnome/themes",
                     "/usr/share/themes",
                     "/usr/gnome/share/themes",  // Debian/Redhat/Solaris
                     "/opt/gnome2/share/themes"  // SuSE
