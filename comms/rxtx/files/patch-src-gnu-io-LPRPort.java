--- src/gnu/io/LPRPort.java.orig	2007-04-26 06:26:05.000000000 +0100
+++ src/gnu/io/LPRPort.java	2015-05-11 16:51:34.000000000 +0100
@@ -77,7 +77,7 @@
 
 	/** Initialize the native library */
 	private native static void Initialize();
-	private final static boolean debug = false;
+	private final static boolean debug = "true".equals( System.getProperty( "gnu.io.rxtx.DEBUG" ) );
 
 	/** Open the named port */
 	public LPRPort( String name ) throws PortInUseException
