--- src/gnu/io/LPRPort.java.orig	2007-04-26 05:26:05 UTC
+++ src/gnu/io/LPRPort.java
@@ -77,7 +77,7 @@ final class LPRPort extends ParallelPort
 
 	/** Initialize the native library */
 	private native static void Initialize();
-	private final static boolean debug = false;
+	private final static boolean debug = "true".equals( System.getProperty( "gnu.io.rxtx.DEBUG" ) );
 
 	/** Open the named port */
 	public LPRPort( String name ) throws PortInUseException
