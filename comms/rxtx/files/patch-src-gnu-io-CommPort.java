--- src/gnu/io/CommPort.java.orig	2007-04-26 05:26:05 UTC
+++ src/gnu/io/CommPort.java
@@ -73,7 +73,7 @@ import java.io.IOException;
   */
 public abstract class CommPort extends Object {
 	protected String name;
-	private final static boolean debug = false;
+	private final static boolean debug = "true".equals( System.getProperty( "gnu.io.rxtx.DEBUG" ) );
 
 	public abstract void enableReceiveFraming( int f ) 
 		throws UnsupportedCommOperationException;
@@ -94,6 +94,7 @@ public abstract class CommPort extends O
 	public abstract int getInputBufferSize();
 	public abstract void setOutputBufferSize( int size );
 	public abstract int getOutputBufferSize();
+	
 	public void close() 
 	{
 		if (debug) System.out.println("CommPort:close()");
@@ -102,12 +103,23 @@ public abstract class CommPort extends O
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
