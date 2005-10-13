$FreeBSD$

--- ../../j2se/src/share/classes/java/awt/Toolkit.java	10 Jan 2005 07:40:41 -0000	1.2
+++ ../../j2se/src/share/classes/java/awt/Toolkit.java	9 Oct 2005 04:11:13 -0000
@@ -809,12 +809,11 @@
 		        try {
                             String defaultToolkit;
 
-				/* XXXBSD: analyze and choose better one */
-                            if (System.getProperty("os.name").equals("Linux")) { 
-                                defaultToolkit = "sun.awt.X11.XToolkit";
+                            if (System.getProperty("os.name").equals("SunOS")) { 
+                                defaultToolkit = "sun.awt.motif.MToolkit";
                             }
                             else { 
-                                defaultToolkit = "sun.awt.motif.MToolkit";
+                                defaultToolkit = "sun.awt.X11.XToolkit";
                             }
 			    nm = System.getProperty("awt.toolkit",
 						defaultToolkit);
