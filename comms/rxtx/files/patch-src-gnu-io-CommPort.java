--- src/gnu/io/CommPort.java.orig	2007-04-26 06:26:05.000000000 +0100
+++ src/gnu/io/CommPort.java	2015-05-11 16:51:34.000000000 +0100
@@ -73,7 +73,7 @@
   */
 public abstract class CommPort extends Object {
 	protected String name;
-	private final static boolean debug = false;
+	private final static boolean debug = "true".equals( System.getProperty( "gnu.io.rxtx.DEBUG" ) );
 
 	public abstract void enableReceiveFraming( int f ) 
 		throws UnsupportedCommOperationException;
@@ -94,6 +94,7 @@
 	public abstract int getInputBufferSize();
 	public abstract void setOutputBufferSize( int size );
 	public abstract int getOutputBufferSize();
+	
 	public void close() 
 	{
 		if (debug) System.out.println("CommPort:close()");
@@ -102,12 +103,23 @@
 		{
 			CommPortIdentifier cp = 
 				CommPortIdentifier.getPortIdentifier(this);
-			if ( cp != null )
+				
+			if (cp != null)
+			{
+				
+				if (debug) System.out.println(" Not Null");
+				
 				cp.getPortIdentifier(this).internalClosePort();
+				
+			}
 		}
 		catch (NoSuchPortException e)
 		{
+			if (debug) System.out.println("CommPort:close(): No Such Port");
 		}
+		
+		if (debug) System.out.println("CommPort:close:Exit");
+		
 	};
 
 	public abstract InputStream getInputStream() throws IOException;
