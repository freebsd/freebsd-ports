--- src/gnu/io/SerialPortEvent.java.orig	2007-04-26 05:26:06 UTC
+++ src/gnu/io/SerialPortEvent.java
@@ -76,6 +76,8 @@ public class SerialPortEvent extends Eve
 	public static final int PE                  =8;
 	public static final int FE                  =9;
 	public static final int BI                 =10;
+	
+	private final static boolean debug = "true".equals( System.getProperty( "gnu.io.rxtx.DEBUG" ) );
 
 	private boolean OldValue;
 	private boolean NewValue;
