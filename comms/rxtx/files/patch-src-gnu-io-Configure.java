--- src/gnu/io/Configure.java.orig	2007-11-18 22:32:41.000000000 +0000
+++ src/gnu/io/Configure.java	2015-05-11 16:51:34.000000000 +0100
@@ -61,6 +61,7 @@
 import java.awt.event.*;
 import java.io.*;
 
+
 class Configure extends Frame
 {
 	Checkbox cb[];
@@ -68,7 +69,9 @@
 	static final int PORT_SERIAL	=	1;
 	static final int PORT_PARALLEL	=	2;
 	int PortType = PORT_SERIAL;
-
+	
+	private final static boolean debug = "true".equals( System.getProperty( "gnu.io.rxtx.DEBUG" ) );
+	
 	private void saveSpecifiedPorts()
 	{
 		String filename;
@@ -212,7 +215,9 @@
 	}
 	public static void main (String[] args)
 	{
+		if (debug) System.out.println("Configure - Before New");
 		new Configure();
+		if (debug) System.out.println("Configure - After New");
 	}
 	String EnumMessage = "gnu.io.rxtx.properties has not been detected.\n\nThere is no consistant means of detecting ports on this operating System.  It is necessary to indicate which ports are valid on this system before proper port enumeration can happen.  Please check the ports that are valid on this system and select Save";
 }
